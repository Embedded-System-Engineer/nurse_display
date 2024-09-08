#include "../inc/appRes.h"


static uint8_t currentRequest = 0;

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Variables>                                                |
 --------------------------------------------------------------------------------------------------------
 */


/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Functions Definitions>                                    |
 --------------------------------------------------------------------------------------------------------
 */
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Functions Implements>                                    |
 --------------------------------------------------------------------------------------------------------
 */

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < updateDisplaysRequest >                                            |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void updateDisplaysRequest                                                    |
 | < @Description       : Request user switch id and room switch id to all active displays in call point|                                                     |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t updateDisplayRequest(uint8_t switchIp) {
    uint8_t buf[3];
    uint8_t FrameState;
    buf[0] = SW_UPDATE_DISPLAY_REQ;
    currentRequest = buf[0];
    buf[1] = SystemIp();
    buf[2] = switchIp;
    FrameState = putDataCh0(buf, 3, 0xFF, RequestFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        currentRequest = 0;
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        currentRequest = 0;
        return (1);
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < DisplayGetConfigReq >                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void DisplayGetConfigReq                                                           |
 | < @Description       : Request Config State                                                 |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t DisplayGetConfigReq() {
    uint8_t buf[2];
    uint8_t FrameState;
    buf[0] = DISPLAY_POWER_ON_REQ;
    currentRequest = buf[0];
    buf[1] = SystemIp();
    FrameState = putDataCh0(buf, 2, 0, RequestFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        currentRequest = 0;
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        currentRequest = 0;
        return (1);
    }
    return (0);

}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < PowerOnRequest >                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void PowerOnRequest                                                           |
 | < @Description       : request data from save unit                                                   |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t PowerOnRequest() {
    uint8_t buf[2];
    uint8_t FrameState;
    buf[0] = SW_POWERON_DISPLAY_REQ;
    currentRequest = buf[0];
    buf[1] = SystemIp();
    FrameState = putDataCh0(buf, 2, 0xFF, RequestFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        currentRequest = 0;
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        currentRequest = 0;
        return (1);
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < GetIpRequest >                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void GetIpRequest                                                             |
 | < @Description       : Response for Start Flash with select address                                  |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t GetIpRequest() {
    uint8_t FrameState;
    uint8_t buf[2];
    buf[0] = SET_IP_RES;
    buf[1] = SystemIp();
    currentRequest = buf[0];
    FrameState = putDataCh0(buf, 2, 0, ResponseFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        currentRequest = 0;
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        currentRequest = 0;
        return (1);
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < ResForConfig >                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void ResForConfig                                                             |
 | < @Description       : Response for Start Flash with select address                                  |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t ResForConfig() {
    uint8_t FrameState;
    uint8_t buf[2];
    buf[0] = DISPLAY_CONFIG_RES;
    buf[1] = SystemIp();
    currentRequest = buf[0];
    FrameState = putDataCh0(buf, 2, 0, ResponseFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        return (1);
    }
    return (0);
}

uint8_t getCurrentRequest() {
    uint8_t current = currentRequest;
    currentRequest = 0;
    return current;
}