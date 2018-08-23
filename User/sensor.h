#ifndef _SENSOR_H_
#define _SENSOR_H_
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"


#define FRONT_PORT GPIOC
#define FRONT_PIN GPIO_Pin_11
#define BEHIND_PORT GPIOC
#define BEHIND_PIN GPIO_Pin_12

#define FRONT_In GPIO_ReadInputDataBit(FRONT_PORT,FRONT_PIN)
#define BEHIND_In GPIO_ReadInputDataBit(BEHIND_PORT,BEHIND_PIN)

void DisInit(void);

uint16_t GetDis(void); // 0前 1后

#endif
