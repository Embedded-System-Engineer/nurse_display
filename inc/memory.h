/* 
 * File:   memory.h
 * Author: hassa
 *
 * Created on April 19, 2023, 12:07 PM
 */

#ifndef MEMORY_H
#define	MEMORY_H
#include "appRes.h"

typedef union {
    uint8_t Options;

    struct {
        unsigned MainView : 1;
        unsigned dangdongState : 1;
    };
} CallPointOptions_t;

typedef struct SystemConfig_s {
    CallPointOptions_t Option;
    uint8_t activeIps[MAX_DEVICE_USED >> 3];
} SystemConfig_t;


/*
 * <@marco system cancel state
 */
#define SYSTEM_DEFALUT_EVENT               0x00
/*
 * <@marco system cancel state
 */
#define SYSTEM_START_ADDRESS_EVENT         0x01
/*
 * <@marco system cancel state
 */
#define SYSTEM_CANCEL_EVENT                0x02
/*
 * <@marco system call state
 */
#define  SYSTEM_ACCEPT_EVENT               0x03
/*
 * <@marco system call state
 */
#define SYSTEM_ASSISSET_EVENT              0x04
/*
 * <@marco system call state
 */
#define SYSTEM_CALL_EVENT                  0x05
/*
 * <@marco system call state
 */
#define SYSTEM_EMG_EVENT                   0x06

#endif	/* MEMORY_H */

