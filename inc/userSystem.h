/* 
 * File:   userSystem.h
 * Author: hassa
 *
 * Created on April 21, 2023, 1:42 AM
 */

#ifndef USERSYSTEM_H
#define	USERSYSTEM_H

#include "appRes.h"

typedef enum {
    CANCEL_STATE = 0,
    CALL_STATE = 1,
    URGENT_STATE = 2,
    CONFIG_STATE = 3,
    NEW_REQUEST_STATE = 4,
} CommandType;

typedef struct {
    uint16_t swId;
    uint16_t RId;
    uint8_t State;
} QueueItem;
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
void RegisterOnUserSystemState(CommandType State);
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

void setCurrentItem(QueueItem currentItem);

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <UserInit>                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void UserInit                                                               |
 | < @Description         : Init all variable in this file                                              |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void UserInit();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <UserCallBack>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void UserCallBack                                                           |
 | < @Description         : run in background                                                           |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void UserCallBack();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <getPeriodIsDone>                                                    |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void getPeriodIsDone                                                        |
 | < @Description         : one Period is done or not                                                   |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t getPeriodIsDone();
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
bool getUserStateInConfig();
#endif	/* USERSYSTEM_H */

