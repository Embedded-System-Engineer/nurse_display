/* 
 * File:   PowerOn.h
 * Author: hassa
 *
 * Created on April 23, 2023, 12:39 PM
 */

#ifndef POWERON_H
#define	POWERON_H

#include "appRes.h"

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <stopPowerOnDisplayData>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void stopPowerOnDisplayData                                                        |
 | < @Description         : stop Request Data from display                                                             |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void stopPowerOnDisplayData();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnInit>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnInit                                                            |
 | < @Description         : Init all data into this file                                                |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void PowerOnInit();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnCallBack>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnCallBack                                                        |
 | < @Description         : Power on task                                                               |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void PowerOnCallBack();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <stopPowerOnDisplayConfig>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void stopPowerOnDisplayConfig                                                        |
 | < @Description         : stop Request config from display                                                             |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void stopPowerOnDisplayConfig();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PoweronRestart>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PoweronRestart                                                        |
 | < @Description         : Power on Restart after change Ip                                                              |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
 void PoweronRestart();
 /*
 --------------------------------------------------------------------------------------------------------
 |                                 <stopPowerOnDisplayConfig>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void stopPowerOnDisplayConfig                                                        |
 | < @Description         : stop Request config from display                                                             |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void startPowerOnData();
#endif	/* POWERON_H */

