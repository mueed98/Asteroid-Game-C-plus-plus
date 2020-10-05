/*
 * enemyBullet.cpp
 *
 *  Created on: May 10, 2018
 *      Author: mueed
 */

#include "enemyBullet.h"

enemyBullet::enemyBullet()
{

}
void enemyBullet::pixelMover()
{
	if(check!=-1)
		y-=20;
		if(y<0)
		check=-1;
		if(check==-1)
		{
		this->x=1500;
		this->y=1500;
		}
}
