#include "sensor.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"
#include "misc.h"

void DisInit(void)
{
	GPIO_InitTypeDef gs;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
  gs.GPIO_Pin=FRONT_PIN;
  gs.GPIO_Mode=GPIO_Mode_IN_FLOATING;
  gs.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(FRONT_PORT,&gs);
	gs.GPIO_Pin=BEHIND_PIN;
  GPIO_Init(BEHIND_PORT,&gs);
}
/**
 * @brief Get the Dis object
 * 前后均未检测到返回0
 * 左前检测到返回1
 * 右后检测到返回2
 * 均检测返回3
 * @return uint16_t 
 */
uint16_t GetDis(void)
{
  uint16_t value=0;
  if(FRONT_In == Bit_RESET){
    value+=1;
  }
  if(BEHIND_In == Bit_RESET){
    value+=2;
  }
	return value;
}
