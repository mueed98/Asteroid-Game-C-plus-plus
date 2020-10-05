/*
 * Bullet.h
 *
 *  Created on: May 4, 2018
 *      Author: mueed
 */
#include"util.h"
#ifndef BULLET_H_
#define BULLET_H_

class Bullet
{
	int x,y,check;
public:
	Bullet(){x=y=check=-1;};
	void display();
	void pixelMover();
	void makeBullet(int x1,int y1);
	void setCheck(int ch);
	int getX(){return x;}
	int getY(){return y;}
};

#endif /* BULLET_H_ */
