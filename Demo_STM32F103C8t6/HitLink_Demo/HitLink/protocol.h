#ifndef __PROTOCOL_H
#define __PROTOCOL_H

#include <stdint.h>
#include "stdio.h"
#include "hitlink_heartbeat.h"
#include "hitlink_attitute.h"
#include "hitlink.h"

/* Private define ------------------------------------------------------------*/
#define FLOAT_SIZE	4
#define INT_SIZE	4
#define UINT32_SIZE	4
#define DOUBLE_SIZE	8
#define	HEARTBEAT	0
#define	ATTITUTE	1

/* Private function prototypes -----------------------------------------------*/
void put_float_buf(char *buffer, float data);
void put_uint32_t_buf(char *buffer, uint32_t data);
void put_int_buf(char *buffer, int data);
#endif
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
