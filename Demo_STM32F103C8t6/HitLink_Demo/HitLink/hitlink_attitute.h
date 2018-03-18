#ifndef __HITLINK_ATTITUTE_H
#define __HITLINK_ATTITUTE_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "hitlink.h"
#include "SYSTICK.h"
#include "protocol.h"
#include "stdio.h"
#include <stdint.h>


/* Private define ------------------------------------------------------------*/
#ifndef HITLINK_ATTITUTE_MSG_ID
#define HITLINK_ATTITUTE_MSG_ID	1
#endif

/* Typedefine line of the basic link----------------------------------------- */
typedef struct __hitlink_attitute_t{
	uint32_t time_stamp;
	float roll;
	float pitch;
	float yaw;
	float roll_speed;
	float pitch_speed;
	float yaw_speed;
}hitlink_attitute_t;



/* Private function prototypes -----------------------------------------------*/
void hitlink_attitute_pack(uint32_t systime_ms,\
							float roll,\
							float pitch,\
							float yaw,\
							float roll_speed,\
							float pitch_speed,\
							float yaw_speed,\
							hitlink_msg *hitlinkmsg);
#endif