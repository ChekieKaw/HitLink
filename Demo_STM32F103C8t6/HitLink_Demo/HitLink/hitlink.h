#ifndef __HITLINK_H
#define __HITLINK_H

#include "stm32f10x.h"
#include "SYSTICK.h"

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Private define ------------------------------------------------------------*/
#ifndef HITLINK_STR
#define HITLINK_STR	0xFE
#endif

#ifndef HITLINK_MAX_LEN
#define HITLINK_MAX_LEN 256
#endif

/* Typedefine line of the basic link----------------------------------------- */
typedef struct __hitlink_msg{
	int start;
	int sequence;
	int payload_len;
	int message;
	u8 payload[HITLINK_MAX_LEN];
	int CRC_h;
	int CRC_l;
	}hitlink_msg;

/* Private function prototypes -----------------------------------------------*/


#endif
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

	