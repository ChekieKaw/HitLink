#ifndef __HITLINK_H
#define __HITLINK_H

#include "stm32f10x.h"
#include "SYSTICK.h"
#include <stdint.h>




/* Private define ------------------------------------------------------------*/
#ifndef HITLINK_STR
#define HITLINK_STR	0xFE
#endif

#ifndef HITLINK_MAX_LEN
#define HITLINK_MAX_LEN 255
#endif

#define HITLINK_MAX_SEQ 255

/* Typedefine line of the basic link----------------------------------------- */
typedef struct __hitlink_msg{
	uint8_t start;
	uint8_t sequence;
	uint8_t payload_len;
	uint8_t message;
	char payload[HITLINK_MAX_LEN];
	uint8_t CRC_h;
	uint8_t CRC_l;
	}hitlink_msg;

/* Private function prototypes -----------------------------------------------*/

void hitlink_calculatelen(hitlink_msg *hitlinkmsg);
void hitlink_init(hitlink_msg *hitlinkmsg);
void hit_link_msg2buffer(hitlink_msg *hitlinkmsg, char *pbuffer);
	
/* Includes ------------------------------------------------------------------*/
#include "protocol.h"
#include "hitlink_heartbeat.h"
#include "hitlink_attitute.h"

#endif
	
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
	