/*************************** (C) 1209 Laboratory *********************************
 * �ļ���  ��led.c
 * ����    ��led Ӧ�ú�����         
 * Ӳ�����ӣ�-----------------
 *          |   PB0 - LED1     |
 *          |   PB1 - LED2     |
 *           ----------------- 
 * ��汾  ��ST3.5.0
 * ����    ��Austin
**********************************************************************************/
#include "led.h"
GPIO_TypeDef *GPIOS[12]  = {GPIOD,GPIOD,GPIOD,GPIOD,GPIOE,GPIOE,GPIOE,GPIOE,GPIOB,GPIOB,GPIOC,GPIOC};//SWR0-11 
u16 PORT[12]= {GPIO_Pin_12,GPIO_Pin_13,GPIO_Pin_14,GPIO_Pin_15,GPIO_Pin_12,GPIO_Pin_13,GPIO_Pin_14,GPIO_Pin_15,GPIO_Pin_6,GPIO_Pin_7,GPIO_Pin_6,GPIO_Pin_7};
/*
 * ��������LED
 * ����  ������LED�õ���I/O��
 * ����  ����
 * ���  ����
 */
 void led(void)
{		
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*����GPIOB������ʱ��*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE); 

	/*ѡ��Ҫ���Ƶ�GPIOB����*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8;	

	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*���ÿ⺯������ʼ��GPIOB*/
  	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_Init(GPIOA, &GPIO_InitStructure);		  

	/* ����ߵ�ƽ����������led��	*/
	GPIO_SetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1);	 
	GPIO_SetBits(GPIOS[1], GPIO_Pin_0 | GPIO_Pin_1);	 
}
/*************************** (C) 1209 Laboratory *********************************/
