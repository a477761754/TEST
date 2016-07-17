/*************************** (C) 1209 Laboratory *********************************
 * 文件名  ：led.c
 * 描述    ：led 应用函数库         
 * 硬件连接：-----------------
 *          |   PB0 - LED1     |
 *          |   PB1 - LED2     |
 *           ----------------- 
 * 库版本  ：ST3.5.0
 * 作者    ：Austin
**********************************************************************************/
#include "led.h"
GPIO_TypeDef *GPIOS[12]  = {GPIOD,GPIOD,GPIOD,GPIOD,GPIOE,GPIOE,GPIOE,GPIOE,GPIOB,GPIOB,GPIOC,GPIOC};//SWR0-11 
u16 PORT[12]= {GPIO_Pin_12,GPIO_Pin_13,GPIO_Pin_14,GPIO_Pin_15,GPIO_Pin_12,GPIO_Pin_13,GPIO_Pin_14,GPIO_Pin_15,GPIO_Pin_6,GPIO_Pin_7,GPIO_Pin_6,GPIO_Pin_7};
/*
 * 函数名：LED
 * 描述  ：配置LED用到的I/O口
 * 输入  ：无
 * 输出  ：无
 */
 void led(void)
{		
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*开启GPIOB的外设时钟*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE); 

	/*选择要控制的GPIOB引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8;	

	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*调用库函数，初始化GPIOB*/
  	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_Init(GPIOA, &GPIO_InitStructure);		  

	/* 输出高电平，开启所有led灯	*/
	GPIO_SetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1);	 
	GPIO_SetBits(GPIOS[1], GPIO_Pin_0 | GPIO_Pin_1);	 
}
/*************************** (C) 1209 Laboratory *********************************/
