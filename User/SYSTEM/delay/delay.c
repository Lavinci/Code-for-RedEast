#include "delay.h"
////////////////////////////////////////////////////////////////////////////////// 	 
//���ʹ��ucos,����������ͷ�ļ�����.
#if SYSTEM_SUPPORT_UCOS
#include "includes.h"					//ucos ʹ��	  
#endif

////////////////////////////////////////////////////////////////////////////////// 	 

static u8  fac_us=0;//us��ʱ������			   
static u16 fac_ms=0;//ms��ʱ������,��ucos��,����ÿ�����ĵ�ms��

void delay_init(u8 SYSCLK)
{
  SysTick->CTRL &=~(1<<2); //??????
  fac_us=SYSCLK/8;
  fac_ms=(u16)fac_us*1000;
}								    

    		
	    								   
void delay_us(u32 nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us; //ʱ�����	  		 
	SysTick->VAL=0x00;        //��ռ�����
	SysTick->CTRL=0x01 ;      //��ʼ���� 	 
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL=0x00;       //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����	 
}
//��ʱnms
//ע��nms�ķ�Χ
//SysTick->LOADΪ24λ�Ĵ���,����,�����ʱΪ:
//nms<=0xffffff*8*1000/SYSCLK
//SYSCLK��λΪHz,nms��λΪms
//��72M������,nms<=1864 
void delay_ms(u16 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL =0x00;           //��ռ�����
	SysTick->CTRL=0x01 ;          //��ʼ����  
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL=0x00;       //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����	  	    
} 

void delayUs(u32 _us)
{
  u32 temp;
  SysTick->LOAD=_us*fac_us;
  SysTick->VAL=0X00;
  SysTick->CTRL=0X01; //????
  do{
    temp=SysTick->CTRL;
  }while( temp&0x01 && !(temp&(1<<16)) );//????????

  SysTick->CTRL=0x00;//????
  SysTick->VAL=0x00;  //????
}

void delayMs(u16 _ms)
{
  u32 temp;
  SysTick->LOAD=_ms*fac_ms;
  SysTick->VAL=0X00;
  SysTick->CTRL=0X01; //????
  do{
    temp=SysTick->CTRL;
  }while( temp&0x01 && !(temp&(1<<16)) );//????????

  SysTick->CTRL=0x00;//????
  SysTick->VAL=0x00;  //????
}

			 


































