
#include "../inc/appRes.h"
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Variables>                                                |
 --------------------------------------------------------------------------------------------------------
 */
/*
 *<@var user Indicator System
 */
static bool gu8cancelStateIsWrite;

/*
 *<@var user Indicator System
 */
static CommandType gu8UserSystem;
/*
 *user Last Indicator System 
 */
static uint8_t gu8OnPeriodIsDone;
/*
 * < @var Timer-Flashing Data
 */
static uint8_t gu8ToggleState;
/*
 * Pointer to Read current Data
 */
static QueueItem item;

/*
 s
 */

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Function Definitions>                                                |
 --------------------------------------------------------------------------------------------------------
 */

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onStartConfig>                                                      |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onStartConfig                                                          |
 | < @Description         : Active On system set new config System                                      |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onStartConfig();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserEMG>                                                         |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserEMG                                                             |
 | < @Description         : user indicator at emg events                                               |      
 | < @return              : void                                                                       |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onUserEMG();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserCall>                                                         |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserCall                                                             |
 | < @Description         : user indicator at call events                                               |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onUserCall();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Function >                                                |
 --------------------------------------------------------------------------------------------------------
 */

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onStartConfig>                                                      |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onStartConfig                                                          |
 | < @Description         : Active On system set new config System                                      |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static void onStartConfig() {
    if (systemIsDateTimeReady() == 0) {
        if (getMainView() == 0) {
            DataTimePlay((uint16_t) csmaGetStationAddress(), (uint16_t) SystemIp(), 1000, 500, 20);
        } else {
            DataTimePlay((uint16_t) SystemIp(), (uint16_t) csmaGetStationAddress(), 1000, 500, 20);
        }
        return;
    }
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserEMG>                                                         |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserEMG                                                             |
 | < @Description         : user indicator at emg events                                               |      
 | < @return              : void                                                                       |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onUserEMG() { /*get Feed back*/
    time_t PeriodToggle;
    time_t PeriodFixed;

    switch (gu8ToggleState) {
        case 0:
            PeriodToggle = (30 * 3000U) / 100;
            DataTimePlay(item.swId, item.RId, (PeriodToggle >> 1), (PeriodToggle >> 2), 2);
            gu8ToggleState = 1;
            break;
        case 1:
            if (systemIsDateTimeReady() == 0) {
                PeriodFixed = (70 * 3000U) / 100;
                DataTimePlay(item.swId, item.RId, PeriodFixed, PeriodFixed, 1);
                gu8ToggleState = 2;
            }
            break;
        case 2:
            if (systemIsDateTimeReady() == 0) {
                gu8ToggleState = 0;
                return (1);
            }
            break;
        default:
            gu8ToggleState = 0;
            break;
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <onUserCall>                                                         |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void onUserCall                                                             |
 | < @Description         : user indicator at call events                                               |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onUserCall() {

    if (gu8ToggleState == 0) {
        gu8ToggleState = 1;
        DataTimePlay(item.swId, item.RId, 3000, 3000, 1);
        return (0);
    }
    if (systemIsDateTimeReady() == 0) {
        gu8ToggleState = 0;
        return (1);
    }
    return (0);
}

static uint8_t onNewRequest() {

    if (gu8ToggleState == 0) {
        gu8ToggleState = 1;
        DataTimePlay(item.swId, item.RId, 500, 250, 2);
        return (0);
    }
    if (systemIsDateTimeReady() == 0) {
        gu8ToggleState = 0;
        return (1);
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < RegisterOnUserSystem >                                             |
 --------------------------------------------------------------------------------------------------------
 | < @Function                   : void RegisterOnUserSystem                                            |
 | < @Description                : user indicator show                                                  |     
 | < @Param  State               : Register with direct state                                           |
 | < @return                     : void                                                                 |
 --------------------------------------------------------------------------------------------------------
 */

void setCurrentItem(QueueItem currentItem) {
    item = currentItem;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < RegisterOnUserSystem >                                             |
 --------------------------------------------------------------------------------------------------------
 | < @Function                   : void RegisterOnUserSystem                                            |
 | < @Description                : user indicator show                                                  |     
 | < @Param  State               : Register with direct state                                           |
 | < @return                     : void                                                                 |
 --------------------------------------------------------------------------------------------------------
 */
void RegisterOnUserSystemState(CommandType State) {
    if (gu8UserSystem != CANCEL_STATE) {
        gu8cancelStateIsWrite = true;
    }
    gu8OnPeriodIsDone = 0;
    gu8ToggleState = 0;
    gu8UserSystem = State;

    systemDateTimeStop();
}
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < RegisterOnUserSystem >                                             |
 --------------------------------------------------------------------------------------------------------
 | < @Function                   : void RegisterOnUserSystem                                            |
 | < @Description                : user indicator show                                                  |     
 | < @Param  State               : Register with direct state                                           |
 | < @return                     : void                                                                 |
 --------------------------------------------------------------------------------------------------------
 */
bool getUserStateInConfig() {
    if (gu8UserSystem == CONFIG_STATE) {
        return (1);
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <UserInit>                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void UserInit                                                               |
 | < @Description         : Init all variable in this file                                              |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void UserInit() {
    gu8UserSystem = CANCEL_STATE;
    gu8ToggleState = 0;
    gu8OnPeriodIsDone = 0;
    gu8cancelStateIsWrite = true;
    systemDateTimeStop();
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <UserCallBack>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void UserCallBack                                                           |
 | < @Description         : run in background                                                           |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void UserCallBack() {
    if (csmaGetStationAddress() == 0) {
        if (systemIsDateTimeReady() == 0 && (eepromIsBusy() == 0)) {
            gu8cancelStateIsWrite = true;
            DataTimePlay(csmaGetStationAddress(), SystemIp(), 1000, 1000, 1);
        }
        return;
    }


    switch (gu8UserSystem) {
        case CANCEL_STATE:
            if (gu8cancelStateIsWrite) {
                _7seg_write_contanst_Char(display_main, '-');
                _7seg_write_contanst_Char(display_extention, '-');
                gu8cancelStateIsWrite = false;
            }
            break;
        case CALL_STATE:
            if (onUserCall()) {
                gu8OnPeriodIsDone = 1;
            }
            break;
        case URGENT_STATE:
            if (onUserEMG()) {
                gu8OnPeriodIsDone = 1;
            }
            break;
        case CONFIG_STATE:
            /*Flash Current Data with 20 ms*/
            onStartConfig();
            break;
        case NEW_REQUEST_STATE:
            if (onNewRequest()) {
                gu8UserSystem = item.State;
            }
            break;
        default:
            gu8UserSystem = CANCEL_STATE;
            break;
    }
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getPeriodIsDone>                                                    |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getPeriodIsDone                                                        |
 | < @Description         : one Period is done or not                                                   |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getPeriodIsDone() {
    if (gu8OnPeriodIsDone) {
        gu8OnPeriodIsDone = 0;
        return (1);
    }
    return (0);
}