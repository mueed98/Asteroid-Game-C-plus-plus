/*
 * Bullet.cpp
 *
 *  Created on: May 4, 2018
 *      Author: mueed
 */

#include "Bullet.h"

void Bullet::display()
{

	if(check!=-1)
	DrawCircle(x,y,7,colors[RED]);
}
void Bullet::pixelMover()
{	if(check!=-1)
	y+=20;
if(y>920)
	check=-1;
if(check==-1)
{
	this->x=1500;
	this->y=1500;
}
}
void Bullet::makeBullet(int x1,int y1)
{
	if(check!=-1)
	{
	x=x1;y=y1;
	display();
	}
	else
	{
		this->x=1500;
			this->y=1500;
	}
	//cout<<"Bullet x="<<x<<" Bullet y="<<y<<endl;
}
void Bullet::setCheck(int ch)
{
	check=ch;
}
