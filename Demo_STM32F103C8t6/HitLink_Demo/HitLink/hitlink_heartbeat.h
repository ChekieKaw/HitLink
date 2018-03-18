#ifndef __HITLINK_HEARTBEAT_H
#define __HITLINK_HEARTBEAT_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "SYSTICK.h"
#include "protocol.h"
#include "stdio.h"
#include <stdint.h>

/* Private define ------------------------------------------------------------*/
#ifndef HITLINK_HEARTBEAT_MSG_ID
#define HITLINK_HEARTBEAT_MSG_ID	0
#endif

/* Typedefine line of the basic link----------------------------------------- */
typedef enum __hitlink_typeenum{Quadrotor,GroundControlSystem,Other_type}HITLINK_TYPEENUM;
typedef enum __hitlink_connect_flagenum{AVALIABLE,UNAVALIABLE}HITLINK_FLAGENUM;
typedef enum __hitlink_stateenum{Lock,Auto,Stable,Other_state}HITLINK_STATEENUM;

typedef struct __hitlink_heartbeat_t{
	uint32_t time_stamp;
	HITLINK_TYPEENUM type;
	HITLINK_FLAGENUM connect_flag;
	HITLINK_STATEENUM system_state;
}hitlink_heartbeat_t;


#endif
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
