/*
 * myAsteroid.cpp
 *
 *  Created on: May 1, 2018
 *      Author: mueed
 */

#include "myAsteroid.h"
#include <iostream>
#include<stdlib.h>

using namespace std;
void DrawAsteroid(int x/*starting x*/, int y/*starting y*/,int ColorNumber, float radius = 6/*Asteroid radius in Units*/,
		const int corners = 7/*Asteroid corners*/)
		{
	int ogr = 6, ogh = 7;

	glPushMatrix();
	float sx = (float) radius / ogr;
	//glTranslatef(x, y, 1);
	//glScalef(sx, 1, 1);

	// Draw Asteroid here
	const int nvertices = 722;
	GLfloat vertices[nvertices][2];
	float hdegree = M_PI / (corners/2);
	float angle = 0;
	for (int i = 0; i < nvertices ; ++i) {
		vertices[i][0] = radius * cos(angle);
		vertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}

	glColor3fv(colors[ColorNumber]); // set the circle color
	glBegin(GL_TRIANGLE_FAN);
	glVertex4f(x, y, 0, 1);
	for (int i = 0; i < nvertices; ++i)
		glVertex4f(x + vertices[i][0], y + vertices[i][1], 0, 1);
	glEnd();

	glPopMatrix();
}

myAsteroid::myAsteroid()
{
	x=y=slopeX=slopeY=fx=fy=splitCheck=-10;
	this->slopeSetter();
	ColorNumber=GetRandInRange(1,137);
	collisionCheck=-1;
}


myAsteroid::myAsteroid(int n1,int n2)
{
	splitCheck=-10;
	x=y=slopeX=slopeY=fx=fy=-10;
	x=n1;
	y = n2;
	ColorNumber=GetRandInRange(1,137);
	collisionCheck=-1;
}
void myAsteroid::xySetter(int x,int y)
{

		if(this->x<0 && this->y<0)
		{
		this->x=x;
		this->y=y;
		}
		else
			{
			slopeX=x;
			slopeY=y;
			slopeSetter();
			}

}
void myAsteroid::slopeSetter()
{int choice=GetRandInRange(-1,1);
if(choice==-1)
	fx=GetRandInRange(-1,1);
if(choice==1)
	fy=GetRandInRange(-1,1);
}
void myAsteroid::pixelMover()
{
	if(collisionCheck==-1)
		{
			if(x>=1020 && y>0){
				x = 0;
			}
			if(y>=840 && x>0){
				y = 0;
			}
			if( x<=0){
					x = 1020;
				}
				if(y<=0){
					y = 840;
				}
				y+=fx;x+=fy;
		}
}
void myAsteroid::display()
{		if(collisionCheck==-1)
		DrawAsteroid(x,y,ColorNumber, 0.8 * 50,6);
		else
			{
			x=-10;
			y=-10;
			DrawAsteroid(x,y,138,0,0);
			}
}
myAsteroid::~myAsteroid()
{

}
void myAsteroid::destroy()
{
	collisionCheck=1;
	xySetter(-10,-10);
}
