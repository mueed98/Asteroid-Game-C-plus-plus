/*
 * enemy.cpp
 *
 *  Created on: May 10, 2018
 *      Author: mueed
 */

#include "enemy.h"

enemy::enemy()
{
	if(GetRandInRange(-1,1)==-1)
	direction='l';
	else
		direction='r';
	dx1=GetRandInRange(20,800);
	dx2=dx1+40;
	dx3=dx1+20;
		dy1=dy2=GetRandInRange(500,800);
		dy3=dy1-50;

}
void enemy::destroy()
{
	this->DeathCheck=0;
	dx1=dx2=dx3=dy1=dy2=dy3=-10;
}
void enemy::display()
{
	myShip::display();

}
