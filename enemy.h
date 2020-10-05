/*
 * enemy.h
 *
 *  Created on: May 10, 2018
 *      Author: mueed
 */
#include"myShip.h"
#ifndef ENEMY_H_
#define ENEMY_H_

class enemy:public myShip
{

public:
	enemy();
	void destroy();
	void display();

};

#endif /* ENEMY_H_ */
