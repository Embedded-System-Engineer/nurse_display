/* 
 * File:   network.h
 * Author: hassa
 *
 * Created on April 23, 2023, 1:43 PM
 */

#ifndef NETWORK_H
#define	NETWORK_H
#include "appRes.h"

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkInit>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkInit                                                            |
 | < @Description         : Init all data into this file                                                |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void NetworkInit();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkdisplayCallBack>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : uint8_t NetworkdisplayCallBack                                                      |
 | < @Description         : find my ip in this list of ips                                              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void NetworkdisplayCallBack();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <setCurrentState>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : CommandType setCurrentState                                                    |
 | < @Description         : interface sysem state and display state                                             |   
 | < @return              : display state                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void ReadRequestsFromPonits();
#endif	/* NETWORK_H */

