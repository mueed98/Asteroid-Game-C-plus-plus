/*
 * myAsteroid.h
 *
 *  Created on: May 1, 2018
 *      Author: mueed
 */
//#include"Board.h"
#include"util.h"
#ifndef MYASTEROID_H_
#define MYASTEROID_H_
class myAsteroid
{
	int x,slopeX,fx;
	int y,slopeY,fy;
	int splitCheck; //to manage splitting of asteroid
	int ColorNumber;
	int collisionCheck;
public:
	myAsteroid();
	myAsteroid(int,int);
void xySetter(int x,int y);
const int getX(){return x;}
const int getY(){return y;}
void setX(int x){this->x=x;}
void setY(int y){this->y=y;}
void slopeSetter();// selects random movement direction
void pixelMover();// moves the asteroid in random direction
void display();
void destroy();
~myAsteroid();
};

#endif /* MYASTEROID_H_ */
