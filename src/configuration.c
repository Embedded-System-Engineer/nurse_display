
#include "../inc/appRes.h"
static uint8_t gu8IP;
static uint8_t gu8WriteState;
/*
 * < @macro APP_START : start of the application       
 */
pst_7seg_t display_main; //room id
pst_7seg_t display_extention; //
static const gpio_t pins1[] = {GPIO_B0, GPIO_A0, GPIO_A1, GPIO_A2};
static const gpio_t pins2[] = {GPIO_A3, GPIO_A4, GPIO_A5};
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <Variables>                                                       |
 --------------------------------------------------------------------------------------------------------
 */
/*
 *<@var : Board Info and configuration var
 */
boardinfo_t gstboardInfo;
/*
 * <@var : system configurations
 */
static SystemConfig_t gsSystemConfig;
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <Internal function Definitions>                                         |
 --------------------------------------------------------------------------------------------------------
 */
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <OnSaveSerial>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void OnSaveSerial                                                           |
 | < @Description         : save serial number On boot section this function reboot system              |   
 | < @return              : void                                                     |          
 --------------------------------------------------------------------------------------------------------
 */
static void OnSaveSerial(uint8_t *buf);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <Internal function >                                         |
 --------------------------------------------------------------------------------------------------------
 */

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <OnSaveSerial>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void OnSaveSerial                                                           |
 | < @Description         : save serial number On boot section this function reboot system              |   
 | < @return              : void                                                     |          
 --------------------------------------------------------------------------------------------------------
 */
static void OnSaveSerial(uint8_t *buf) {
    ATOMIC_BEGIN
    copyBuff((uint8_t *) & gstboardInfo.Time, (&buf[0]) + 3, 4);
    copyBuff((uint8_t*) & gstboardInfo.Code, (&buf[0]) + 9, 6);
    gu8WriteState = 6;
    ATOMIC_END
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <OnSaveIp>                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void OnSaveIp                                                               |
 | < @Description         :save Ip and Re-boot system                                                   |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void OnSaveIp(uint8_t Ip) {
    ATOMIC_BEGIN
    gu8IP = Ip;
    csmaInitStationIp(gu8IP);
    gu8WriteState = 3;
    ATOMIC_END
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getBuzzerState>                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getBuzzerState                                                         |
 | < @Description         : get State of the buzzer on Or off                                           |   
 | < @return              : 0 is off and  1 is on                                                       |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getDangdongState() {
    return gsSystemConfig.Option.dangdongState;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getMainView>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getMainView                                                            |
 | < @Description         : get system show switch id in main and room id in ex                         |   
 | < @return              : 0 is sytem show switch is in main , 1 system show room id in main           |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getMainView() {
    return gsSystemConfig.Option.MainView;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <ConfigurationInit>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void ConfigurationInit                                                      |
 | < @Description         : get Init all data in this File                                              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void ConfigurationInit() {
    display_main = Create_7seg_Display(pins1, 4, 0);
    display_extention = Create_7seg_Display(pins2, 3, 0);
    gu8IP = 1;
    gu8WriteState = 0;
    setBuff((uint8_t *) & gstboardInfo, 0x00, sizeof (boardinfo_t));
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <OnSaveConfiguration>                                                |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void OnSaveConfiguration                                                    |
 | < @Description         : save configuartion On boot section this function reboot system              |   
 | < @return              : 0 is off and  1 is on                                                       |          
 --------------------------------------------------------------------------------------------------------
 */
void OnSaveConfiguration(uint8_t *buf) {
    ATOMIC_BEGIN
    copyBuff(&gsSystemConfig, buf, sizeof (SystemConfig_t));
    ATOMIC_END
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <noSerial>                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void noSerial                                                               |
 | < @Description         : system have serial or not                                                   |   
 | < @return              : 0 is not have a serial and  1 system have a serial                          |          
 --------------------------------------------------------------------------------------------------------
 */
bool SystemIsSerial() {
    if (gstboardInfo.Time != 0) {
        return (true);
    }
    return (false);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemIp>                                                            |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t SystemIp                                                             |
 | < @Description         : get system ip                                                                |   
 | < @return              : void                                                                         |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t SystemIp() {
    return gu8IP;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <EEpromCallback>                                                             |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t EEpromCallback                                                              |
 | < @Description         : get ip from eeprom                                                              |   
 | < @return              : return system ip                                                            |          
 --------------------------------------------------------------------------------------------------------
 */
void EEpromCallback() {


    if (eepromIsBusy()) {
        return;
    }
    switch (gu8WriteState) {
        case 0:
            eepromRequestSterm(0, 1);
            gu8WriteState = 1;
            break;
        case 1:
            eepromRead(&gu8IP);
            if (gu8IP == 0 || gu8IP >= MAX_DEVICE_USED) {
                gu8IP = 1;
            }
            gu8WriteState = 4;
            break;
        case 2:
            break;
        case 3:
            eepromWriteBuf(0, 1, &gu8IP);
            gu8WriteState = 2;
            break;
        case 4:
            eepromRequestSterm(1, sizeof (boardinfo_t));
            gu8WriteState = 5;
            break;
        case 5:

            eepromRead((uint8_t *) & gstboardInfo);
            gu8WriteState = 7;
            break;
        case 6:
            eepromWriteBuf(1, sizeof (boardinfo_t), (uint8_t *) & gstboardInfo);
            gu8WriteState = 7;
            break;
        case 7:
        {
            if (gstboardInfo.Time == 0) {
                _7seg_Display_write_string(display_main, "oFF", 1);
                _7seg_Display_write_string(display_extention, "oFF", 1);
            } else if (gstboardInfo.Time == 0xFFFFFFFF) {
                ATOMIC_BEGIN
                gstboardInfo.CH0 = 0;
                gstboardInfo.CH1 = 0;
                gstboardInfo.Code = 0;
                gstboardInfo.PatchNumber = 0;
                gstboardInfo.PrintCode = 0;
                gstboardInfo.Time = 0x00000000;
                ATOMIC_END
                _7seg_Display_write_string(display_main, "oFF", 1);
                _7seg_Display_write_string(display_extention, "oFF", 1);
            }
            ATOMIC_BEGIN
            csmaInitStationIp(gu8IP);
            csmaSaveSerialRegister(OnSaveSerial);
            csmaloadConfig(gstboardInfo.CH0, gstboardInfo.Time);
            ATOMIC_END
            gu8WriteState = 2;
        }
            break;
        default:
            gu8WriteState = 0;
            break;
    }


}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <findipFromListips>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t findipFromListips                                                      |
 | < @Description         : find my ip in this list of ips                                              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
bool ipIsActive(uint8_t address) {
    uint8_t ip = address - 1;
    //get byte index
    uint8_t byteIndex = ip >> 3;
    uint8_t bitIndex = ip & 7;
    if (bitRead(gsSystemConfig.activeIps[byteIndex], bitIndex)) {
        return true;
    }
    return false;
    // get bit index
}