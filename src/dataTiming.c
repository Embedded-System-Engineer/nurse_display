#include "../inc/appRes.h"


/*
 <@var Time of show Data on display
 */
static uint16_t gu16Period[2];
/*
 <@var number of repeat Period
 */
static uint8_t gu8Duration;

static uint8_t gu8State = 0;
/*
 <@var Data of main Display
 */
static uint16_t gu16MainDisplay;
/*
 <@var Data of main Display
 */
static uint16_t gu16ExDisplay;
/*
 * <@var time traget is done
 */
static stTimer_TimeOut_t gstFrequncy;

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <DataTimePlay>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void DataTimePlay                                                           |
 | < @Description         : flahing data Into buffer                                                    |   
 | < @Param swID          : Switch id  display data show                                                |
 | < @PAram RID           : room id display data show                                                   |
 | < @Param Period        : Time Required Ton and off display                                           |
 | < @Param  Toff         : off Time of the Display                                                     |
 | < @Param duration      : number of repeat counter                                                    |
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void DataTimePlay(uint16_t swID, uint16_t RID, uint16_t Period, uint16_t Ton, uint8_t duration) {
    gu16Period[0] = Ton;
    gu16Period[1] = Period - Ton;
    gu8Duration = duration;
    gu8State = 1;
    if (getMainView()) {
        gu16MainDisplay = swID;
        gu16ExDisplay = RID;
    } else {
        gu16MainDisplay = RID;
        gu16ExDisplay = swID;
    }

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <DataTimeCallBack>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void DataTimeCallBack                                                       |
 | < @Description         : run task in background                                                      |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void DataTimeCallBack() {

    if (SystemIsSerial() == false) {
        return;
    }

    switch (gu8State) {
        case 0:
            break;
        case 1: //start state 
            if (gu8Duration == 0) {
                gu8State = 0;
                return;
            }

            if (gu16Period[0] != 0) {
                //write 
                _7seg_Display_write_Number(display_main, gu16MainDisplay, 1);
                _7seg_Display_write_Number(display_extention, gu16ExDisplay, 1);
                sysSetPeriodMS(&gstFrequncy, gu16Period[0]);
                gu8State = 2;
                return;
            }

            if (gu16Period[1] != 0) {
                _7seg_clear_display(display_main);
                _7seg_clear_display(display_extention);
                sysSetPeriodMS(&gstFrequncy, gu16Period[1]);
                gu8State = 3;
                return;
            }



            break;
        case 2: //on time
            if (sysIsTimeoutMs(&gstFrequncy) == 0) {
                if (gu16Period[1] != 0) {
                    _7seg_clear_display(display_main);
                    _7seg_clear_display(display_extention);
                    sysSetPeriodMS(&gstFrequncy, gu16Period[1]);
                    gu8State = 3;
                    return;
                }
                gu8State = 1;
                gu8Duration--;
            }
            break;
        case 3: // off time
            if (sysIsTimeoutMs(&gstFrequncy) == 0) {
                gu8State = 1;
                gu8Duration--;
            }
            break;
        default:
            break;

    }
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <DataTimeInit>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void DataTimeInit                                                           |
 | < @Description         : init all data into this file                                                |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void DataTimeInit() {
    gu8State = 0;
    gu8Duration = 0;
    gu16Period[0] = 0;
    gu16Period[1] = 0;

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <systemIsDateTimeReady>                                                      |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void systemIsDateTimeReady                                                          |
 | < @Description         : get status of the timing of the Data                                        |      
 | < @return              : 0 done , 1 is busy                                                          |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t systemIsDateTimeReady() {
    return gu8State;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <systemIsDateTimeStop>                                               |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void systemIsDateTimeStop                                                   |
 | < @Description         : stop running time                                                           |      
 | < @return              : 0 done , 1 is busy                                                          |          
 --------------------------------------------------------------------------------------------------------
 */
void systemDateTimeStop() {
    gu16Period[0] = 0;
    gu16Period[1] = 0;
    gu8Duration = 0;
    gu8State = 0; /*Reset all Data*/
}