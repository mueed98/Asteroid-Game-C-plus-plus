/*
 * level.h
 *
 *  Created on: May 3, 2018
 *      Author: mueed
 */

#ifndef LEVEL_H_
#define LEVEL_H_
#include"Board.h"
#include"util.h"
#include <iostream>
#include<string>
//#include"myAsteroid.h"
//#include"myShip.h"
using namespace std;

class level
{
	int levelCount;
	int astCount;
	int fps;
	int score;
public:
	level();
	void setAsteroidCount(int x){this->astCount=x;}
	int getAsteroidCount()const{return astCount;}
	void plusScore();
	int getLevel()const;
	int getScore()const;
	int getFps()const;
};

#endif /* LEVEL_H_ */
