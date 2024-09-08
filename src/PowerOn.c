#include "../inc/appRes.h"
/*
 <@var Power on state 
 */
static uint8_t gu8PowerOnStateConfig;
/*
 *<@var Power on Time out to send Frame 
 */
static stTimer_TimeOut_t gstPowerOnTimeOutConfig;

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnCallBackData>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnCallBack                                                        |
 | < @Description         : Power on task                                                               |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void PowerOnCallBackConfig();

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnInit>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnInit                                                            |
 | < @Description         : Init all data into this file                                                |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void PowerOnInit() {
    gu8PowerOnStateConfig = 0;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnCallBack>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnCallBack                                                        |
 | < @Description         : Power on task                                                               |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void PowerOnCallBack() {

    if (!SystemIsSerial()) {
        gu8PowerOnStateConfig = 0;
        return;
    }


    if (csmaGetStationAddress() == 0) {
        gu8PowerOnStateConfig = 0;
        return;
    }
    PowerOnCallBackConfig();
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PoweronRestart>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PoweronRestart                                                        |
 | < @Description         : Power on Restart after change Ip                                                              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void PoweronRestart() {
    gu8PowerOnStateConfig = 0;
}


/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnCallBackData>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnCallBack                                                        |
 | < @Description         : Power on task                                                               |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void PowerOnCallBackConfig() {

    switch (gu8PowerOnStateConfig) {
        case 0:
            if (DisplayGetConfigReq()) {
                sysSetPeriodMS(&gstPowerOnTimeOutConfig, 200);
                gu8PowerOnStateConfig = 1;
            }
            break;
        case 1:
            if (sysIsTimeoutMs(&gstPowerOnTimeOutConfig) == 0) {
                gu8PowerOnStateConfig = 0;
            }
            break;
        case 2:/*stop case*/
            break;
        default:
            gu8PowerOnStateConfig = 0;
            break;
    }
}



/*
 --------------------------------------------------------------------------------------------------------
 |                                 <stopPowerOnDisplayConfig>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void stopPowerOnDisplayConfig                                                        |
 | < @Description         : stop Request config from display                                                             |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void stopPowerOnDisplayConfig() {
    gu8PowerOnStateConfig = 2;
}
