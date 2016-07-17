/*
  ******************************************************************************
  * @file    D:\_program\STM32\Practice\User
  * @author  ������
  * @version V3.5.0
  * @date    07-April-2014
  * @brief   Main.c
  ******************************************************************************
*/  
#include "stm32f10x.h"
#include "led.h"
#include "sys.h"

/*
  * @brief  ������.
  * @param  None
  * @retval None
*/

void Delay(__IO u32 nCount);

int main(void)
{
	u8 i=0;
	led();
	
  while (1)
  {			
  		i++;
   		LED1( ON );			  // ��
		Delay(0x3FFFEF);
		PAout(8)=!PAin(8);	  //ALIEN��
		LED1( OFF );		  // ��
		
		LED2( ON );
		Delay(0x3FFFEF);
//		PAout(8)=1;
		LED2( OFF );
  }
}

void Delay(__IO u32 nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
} 

/******************* (C) COPYRIGHT 2014 1209-Laboratory *****END OF FILE****/
