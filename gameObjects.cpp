/*
 * gameObjects.cpp
 *
 *  Created on: May 10, 2018
 *      Author: mueed
 */

#include "gameObjects.h"

gameObjects::gameObjects()
{
	this->alien=new enemy[4];
	this->myBullet=new Bullet[500];
	this->ast=new myAsteroid[1000];

}

gameObjects::~gameObjects() {
	// TODO Auto-generated destructor stub
}

