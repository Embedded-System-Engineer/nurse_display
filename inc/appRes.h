/*
--------------------------------------------------------------------------------------------------
|                           < Module  Definition >                                               | 
--------------------------------------------------------------------------------------------------
| < FILE                     : res.h                                                             |                                  
| < Author                   : Hassan Elsaied                                                    |
| < Version                  : Mega2v241022                                                      |
| < Refences                 : no refence                                                        |
| < SRAM USAGE               : header file                                                       |
| < PROGRAM USAGE            : header file                                                       |                                      
| < Hardware Usage           : header file                                                       |
| < File Created             : 24-10-2022                                                        |
--------------------------------------------------------------------------------------------------
 */
#ifndef XC_RES_H
#define	XC_RES_H
#define DISPLAY_MAX_MAIN_DIGIT       (4)
#define DISPLAY_MAX_EX_DIGIT         (3)
#define QUEUE_SIZE                   (8)


#include "../lib/inc/mega.h"
#include "../../../../../CMD.h"
#include "../../../../../boardinfo.h"
#include "memory.h"
#include "Configuration.h"
#include "network.h"

#include "userSystem.h"
#include "dataTiming.h"
#include "Requests.h"
#include "PowerOn.h"


extern pst_7seg_t display_main; //room id
extern pst_7seg_t display_extention; //

#endif	/* XC_HEADER_TEMPLATE_H */

