/* 
 * File:   boardinfo.h
 * Author: hassa
 *
 * Created on April 11, 2023, 7:42 PM
 */

#ifndef BOARDINFO_H
#define	BOARDINFO_H



#define BoardInfoAddress        0x06C
#define NUMBER_OF_DISPLAY_SUPPORT   (4)

typedef struct SystemSerial_s {
    time_t Time;
    uint8_t Code;
    uint8_t PatchNumber;
    uint16_t PrintCode;
    uint8_t CH0;
    uint8_t CH1;
} SystemSerial_t;

typedef struct bordinfo_s {
    uint8_t State;
    SystemSerial_t SystemSerial;
    uint8_t ip;
} boardinfo_t;



#endif	/* BOARDINFO_H */

