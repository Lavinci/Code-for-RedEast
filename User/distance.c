#include "distance.h"
#include "vl53l0.h"
#include "stm32_i2c.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"
#include "misc.h"


#define SEL1_PORT GPIOC
#define SEL1_PIN GPIO_Pin_12
#define SEL2_PORT GPIOC
#define SEL2_PIN GPIO_Pin_11

#define Out1_On GPIO_SetBits(SEL1_PORT,SEL1_PIN)
#define Out1_Off GPIO_ResetBits(SEL1_PORT,SEL1_PIN)
#define Out2_On GPIO_SetBits(SEL2_PORT,SEL2_PIN)
#define Out2_Off GPIO_ResetBits(SEL2_PORT,SEL2_PIN)

extern VL53L0X_Error vl53l0x_status;
extern VL53L0X_RangingMeasurementData_t vl53l0x_data;
extern VL53L0X_Dev_t vl53l0x_dev;


void DisInit(void)
{
	GPIO_InitTypeDef gs;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
  gs.GPIO_Pin=SEL1_PIN;
  gs.GPIO_Mode=GPIO_Mode_Out_PP;
  gs.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(SEL1_PORT,&gs);
	gs.GPIO_Pin=SEL2_PIN;
  GPIO_Init(SEL2_PORT,&gs);
	
	vl53l0x_init();
}

uint16_t GetDis(u8 select)
{
		if(vl53l0x_status == VL53L0X_ERROR_NONE)
		{
			switch(select)
			{
				case 0:Out1_Off,Out2_Off;break;
				case 1:Out1_On,Out2_Off;break;
        case 2:Out1_Off,Out2_On;break;
				case 3:Out1_On,Out2_On;break;
        default:break;
			}
			return (vl53l0x_start_single_test(&vl53l0x_dev, &vl53l0x_data));
		}
		else
		{
			return 999;
		}
}
