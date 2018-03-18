/******************** (C) COPYRIGHT  ���������˻�����ϵͳ˫������ ********************************
 * �ļ��� 	��main.c
 * ����		����Ҫ����ɶԷ������ݣ����������ķ��Ͳ���
 * ��汾 	��V3.50
 * ����		��Chekie Kaw
 * GitHub	��chekie_kaw https://github.com/ChekieKaw/
 * �汾����	�� 2018-03-18
 * ���Է�ʽ	��J-Link-OB
**********************************************************************************/

//ͷ�ļ�
#include "stm32f10x.h"
#include "led.h"
#include "SYSTICK.h"
#include "usart.h"
#include "i2c.h"
#include <stdio.h>
#include "string.h"
#include "hitlink.h"
#include "protocol.h"

hitlink_msg msg;
hitlink_heartbeat_t heartbeat;

void msg_init_heartbeat(hitlink_heartbeat_t *heartbeat);
void msg_init_hitlink(hitlink_msg *hitlink_msg);
char hitlink_msg_buffer[(HITLINK_MAX_LEN+6)];

/**
  * @file   main
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	int msg_len=0;
	int j=0;
    SYSTICK_Init();
    USART1_Config();
    LED_GPIO_Config();	
    msg_init_heartbeat(&heartbeat);
	msg_init_hitlink(&msg);
	hit_link_msg2buffer(&msg,hitlink_msg_buffer);
	msg_len = strlen(hitlink_msg_buffer);
	
    for(j=0;j<msg_len;j++)
	{
		USART_SendData(USART1,hitlink_msg_buffer[j]);
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);// wait
	}
    
}

void msg_init_heartbeat(hitlink_heartbeat_t *heartbeat)
{
	heartbeat->time_stamp = 0x11111111;
	heartbeat->type = Quadrotor;
	heartbeat->system_state = Auto;
	heartbeat->connect_flag = UNAVALIABLE;
}

void msg_init_hitlink(hitlink_msg *hitlink_msg)
{
	hitlink_init(hitlink_msg);
//	hitlink_calculatelen��hitlink_msg);
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/





