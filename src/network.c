
#include "../inc/appRes.h"





static uint8_t gu8NetworkDisplayReq;





/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkClientSystem>                                                |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkClientSystem                                                    |
 | < @Description         : any Response can be handel from this function                               |   
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkClientSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkHostSystem>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkHostSystem                                                      |
 | < @Description         : any request can be handel from this function                                |
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkHostSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data);

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkInit>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkInit                                                            |
 | < @Description         : Init all data into this file                                                |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void NetworkInit() {
    OnClientFrameCh0(NetworkClientSystem);
    OnHostFrameCh0(NetworkHostSystem);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkClientSystem>                                                |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkClientSystem                                                    |
 | < @Description         : any Response can be handel from this function                               |   
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkClientSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data) {


    if (!SystemIsSerial()) {
        return (1);
    }


    if (Data[0] == DISPLAY_POWER_ON_RES) {
        if (Data[1] == SystemIp()) {
            sendFreeFrame();
            OnSaveConfiguration(Data + 2);
            stopPowerOnDisplayConfig();
        }
        return (1);
    }
    return (1);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkHostSystem>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkHostSystem                                                      |
 | < @Description         : any request can be handel from this function                                |
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkHostSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data) {

    if (!SystemIsSerial())
        return (1);



    if (Data[0] == SW_START_CONFIG_REQ && SA == csmaGetMaxAddress()) {
        if (Data[1] == 0) {
            gu8NetworkDisplayReq = 1;
            //get last state and saved
            RegisterOnUserSystemState(CONFIG_STATE);
        } else {
            RegisterOnUserSystemState(CANCEL_STATE);
        }
        return (1);
    }


    if (Data[0] == SET_IP_REQ && SA == csmaGetMaxAddress()) {
        if (Data[1] != SystemIp()) {
            OnSaveIp(Data[1]);
            PoweronRestart();
        }
        RegisterOnUserSystemState(CANCEL_STATE);
        return (1);
    }


    if (Data[0] == DISPLAY_CONFIG_REQ) {
        if (Data[1] == SystemIp()) {
            stopPowerOnDisplayConfig();
            gu8NetworkDisplayReq = 2;
            OnSaveConfiguration((uint8_t *) (Data + 2));
            RegisterOnUserSystemState(CANCEL_STATE);
        }
        return (1);
    }



    if (Data[0] == SW_UPDATE_DISPLAYS_REQ) {
        if (!ipIsActive(Data[1])) {
            return (1);
        }

        if (getUserStateInConfig()) { // system on config
            return (1);
        }
        /*Insert in queue or Delete */
        QueueItem item;
        item.State = Data[2];
        copyBuff(&item.swId, Data + 3, 4);
        setCurrentItem(item);
        if (Data[7] == 0) {
            RegisterOnUserSystemState(item.State);
        } else {
            RegisterOnUserSystemState(NEW_REQUEST_STATE);
        }
    }
    if (Data[0] == SW_UPDATE_DISPLAY_REQ) {
        RegisterOnUserSystemState(CANCEL_STATE);
        return (1);
    }

    return (1);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkdisplayCallBack>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t NetworkdisplayCallBack                                                      |
 | < @Description         : find my ip in this list of ips                                              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void NetworkdisplayCallBack() {
    switch (gu8NetworkDisplayReq) {
        case 0:
            break;
        case 1:
            if (GetIpRequest()) {
                gu8NetworkDisplayReq = 0;
            }
            break;
        case 2:
            if (ResForConfig()) {
                gu8NetworkDisplayReq = 0;
            }
            break;
        case 3:
            if (sendFreeFrame()) {
                gu8NetworkDisplayReq = 0;
            }
            break;
        default:
            gu8NetworkDisplayReq = 0;
            break;
    }
}


