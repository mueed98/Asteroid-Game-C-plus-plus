/*
 * gameObjects.h
 *
 *  Created on: May 10, 2018
 *      Author: mueed
 */

#ifndef GAMEOBJECTS_H_
#define GAMEOBJECTS_H_
#include"myShip.h"
#include"enemy.h"
#include"Bullet.h"
#include"myAsteroid.h"

class gameObjects:public myAsteroid,Bullet,enemy,myShip
{

public:
	myShip Captain;
	myAsteroid *ast;
	Bullet *myBullet;
	enemy *alien;
	gameObjects();
	virtual ~gameObjects();
};

#endif /* GAMEOBJECTS_H_ */
