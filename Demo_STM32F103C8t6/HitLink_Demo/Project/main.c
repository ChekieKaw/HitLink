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



void I2C_Test(void);


/**
  * @file   main
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
    SYSTICK_Init();
    USART1_Config();
    LED_GPIO_Config();	
    I2C_Configuration();
    printf("\r\n ����һ��I2C����(AT24C08)��д�������� \r\n");
    I2C_Test();
    while (1)
    {
     LEDXToggle(LED1);
    LEDXToggle(LED2);
    LEDXToggle(LED3);
    delay_ms(500);
    }
    
}


/*********************************************************************************************************
      END FILE
*********************************************************************************************************/





