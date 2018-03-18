#include "stm32f10x.h"
#include "hitlink.h"
#include "usart.h"
#include "systick.h"

hitlink_msg hitlink;

void hitlink_init(hitlink_msg *hitlinkmsg)
{
	hitlinkmsg->start = HITLINK_STR;
	hitlinkmsg->CRC_h=0;
	hitlinkmsg->CRC_l=0;
}

void hitlink_cacluatelen(hitlink_msg *hitlinkmsg)
{
	int flag=0;
	int len=0;
	for (flag=HITLINK_MAX_LEN-1;flag>=0;flag--)
	{
		if(hitlinkmsg->payload[flag]!=0x00)
			break;
	}
	len=flag+1;
	hitlinkmsg->payload_len=len;
}

void hit_link_pack_buff