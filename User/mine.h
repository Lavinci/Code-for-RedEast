#ifndef _MINE_H_
#define _MINE_H_

//速度式
void SABCD(long int MotoASpeed,long int MotoBSpeed,long int MotoCSpeed,long int MotoDSpeed);

void Go(long int speed,long int time);
void Back(long int speed,long int time);
void TurnLeft(long int speed,long int time);
void TurnRight(long int speed,long int time);
void LGo(long int speed,long int time);
void RGo(long int speed,long int time);

void delayy(int time);
void XunJi(long int time);
void XunJi2(long int time);

//位置式
void GoPosition(long long int x,long long int y,long int time);




#endif
