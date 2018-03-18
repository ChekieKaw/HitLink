/******************** (C) COPYRIGHT  哈工大无人机飞行系统双创基地 ********************************
 * 文件名 	：main.c
 * 描述		：主要是完成对飞行数据（心跳包）的发送操作
 * 库版本 	：V3.50
 * 作者		：Chekie Kaw
 * GitHub	：chekie_kaw https://github.com/ChekieKaw/
 * 版本更新	： 2018-03-18
 * 调试方式	：J-Link-OB
**********************************************************************************/

//头文件
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
    printf("\r\n 这是一个I2C外设(AT24C08)读写测试例程 \r\n");
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





