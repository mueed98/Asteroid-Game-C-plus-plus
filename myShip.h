/*
 * myShip.h
 *
 *  Created on: May 2, 2018
 *      Author: mueed
 */

#ifndef MYSHIP_H_
#define MYSHIP_H_
#include"util.h"
class myShip
{
protected:
	int dx1,dx2,dx3,dy1,dy2,dy3;
	char direction;
	int collisionCheck;
	int DeathCheck;
public:
 void display();
int get_dx3(){return dx3;}
int get_dy3(){return dy3;}
	int getDeathCount()
	{return DeathCheck;}
	myShip();
	 void pixelMover();
	void shipMover(int l=0,int r=0,int u=0,int d=0);
	void shipRotate();
	char getMoveDirection()
	{return direction;}//to get direction like up,left to use for bullet accuracy
	 void destroy();
};

#endif /* MYSHIP_H_ */
