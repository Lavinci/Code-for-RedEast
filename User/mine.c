#ifndef _MINE_H_
#define _MINE_H_
#include "stm32f10x.h"
#include "sys.h"
#include "mine.h"
#include "sensor.h"


extern long int Target_A,Target_B,Target_C,Target_D;
extern int delay_5ms;
extern u8 delay_flag;
extern u8 delay_flag1;
extern float Move_X,Move_Y,Move_Z;
int delay_5ms1;

void delayy(int time)
{
	delay_flag=1;
	delay_5ms=0;
	while(delay_5ms<time){oled_show();}//{;} //
	delay_flag=0;
}

void SABCD(long int MotoASpeed,long int MotoBSpeed,long int MotoCSpeed,long int MotoDSpeed)
{
  Target_A = MotoASpeed;
  Target_B = MotoBSpeed;
  Target_C = MotoCSpeed;
  Target_D = MotoDSpeed;
}

void Stop()
{
	SABCD(0,0,0,0);
}

void Go(int speed,int time)
{
	SABCD(speed,speed,speed,speed);
	delayy(time);
}

void Back(int speed,int time)
{
	SABCD(-speed,-speed,-speed,-speed);
				
	delayy(time);
}

void TurnLeft(int speed,int time)
{
	SABCD(-speed,-speed,speed,speed);
				
	delayy(time);
}

void TurnRight(int speed,int time)
{
	SABCD(speed,speed,-speed,-speed);
				
	delayy(time);
}

void LGo(int speed,int time)
{
	SABCD(speed,0,speed,0);
				
	delayy(time);
}

void RGo(int speed,int time)
{
	SABCD(0,speed,0,speed);
				
	delayy(time);
}

void Left(long int speed,long int time)
{
	SABCD(speed,-speed,speed,-speed);				
	delayy(time);
}
void Right(long int speed,long int time)
{
	SABCD(-speed,speed,-speed,speed);				
	delayy(time);
}

void walk(long int Runtime,long int Alltime)
{
	uint16_t status;
	delay_flag1=1;
	delay_5ms1=0;
	while(delay_5ms1<Alltime)
	{
		status=GetDis();
		if(status >= 8) {Stop();delay_5ms1=Alltime;}
		switch(status)
		{
			case 0: TurnLeft(10,1);break;
			case 1: Right(10,1);break;
			case 2:	Left(10,1);break;
			case 3: Go(25,Runtime);break;
			case 4: TurnRight(10,1);break;
			default:OLED_ShowString(10,40,"Unknow!!");OLED_Refresh_Gram();break;
		}
	}
	delay_flag1=0;
}

void walk2(long int time)
{
	uint16_t status;
	status=GetDis();
	switch(status)
	{
		case 0: Go(10,time);break;
		case 1: LGo(10,time);break;
		//case 2:	RGo(10,50);break;
		//case 3: Go(10,50);break;
		default: OLED_ShowString(10,40,"Unknow!!");OLED_Refresh_Gram();break;
	}
}

void GoPosition(long int x,long int y,long int time)
{
			Move_X=x;
			Move_Y=y;

	delayy(time);
}


#endif
