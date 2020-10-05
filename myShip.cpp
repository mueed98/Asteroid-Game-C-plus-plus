/*
 * myShip.cpp
 *
 *  Created on: May 2, 2018
 *      Author: mueed
 */

#include "myShip.h"
myShip::myShip()
{
	dx1=420;dx2=460;dx3=440;
	dy1=50;dy2=50;dy3=100;
//	int choice=GetRandInRange(-1,1);
//	if(choice==-1)
//		fx=GetRandInRange(-1,1);
//	if(choice==1)
//		fy=GetRandInRange(-1,1);
	direction='u';
	collisionCheck=0;
	DeathCheck=3;
}

void myShip::display()
{	if(DeathCheck<=0)
		{
			DrawTriangle(0,0,0,0,0,0,colors[138]);
					DrawTriangle(0,0,0,0,0,0,colors[5]);
					DrawString(get_dx3(),get_dy3(),"Shooter Destroyed", colors[5]);

					dx1=dx2=dx3=-10;
						dy1=dy2=dy3=-10;
		}
if(DeathCheck>0)
		{
			DrawTriangle(dx1-4,dy1-2,dx2+4,dy2-2,dx3,dy3+4,colors[137]);
			DrawTriangle(dx1,dy1,dx2,dy2,dx3,dy3,colors[7-DeathCheck]);

			pixelMover();
			shipMover();
		}
	//cout<<"Ship x="<<dx3<<"Ship y="<<dy3<<endl;
}
void myShip::pixelMover()
{
	if(DeathCheck>0)
	{
			if(this->direction=='u')
			{
				dy2+=10;
				dy1+=10;
				dy3+=10;
			}
			if(this->direction=='d')
			{
						dy2-=10;
						dy1-=10;
						dy3-=10;
			}
			if(this->direction=='l')
				{
				dx2-=10;
				dx1-=10;
				dx3-=10;
				}
			if(this->direction=='r')
			{
				dx1+=10;
				dx2+=10;
				dx3+=10;
			}
	}
	else
	{
		dx1=dx2=dx3=dy2=dy1=dy3=+1000;
	}
}
void myShip::shipMover(int l,int r,int u,int d)
{
	if(DeathCheck>-1)
	{
				if(l!=0)
				direction= 'l';
				if(r!=0)
				direction= 'r';
				if(u!=0)
				direction= 'u';
				if(d!=0)
				direction= 'd';
				if(dx1<=-30)
				{
				dx1=940;
				dx2=980;
				dx3=(dx1+dx2)/2;
				}
				if(dx2>1010)
				{
				dx1=-20;
				dx2=20;
				dx3=(dx1+dx2)/2;
				}
				if(dy3>880)
				{
				dy3=50;
				dy1=dy2=0;
				}
				if(dy1<-40)
				{
				dy3=850;
				dy1=dy2=800;
				}
	}
}

void myShip::destroy()
{
	//collisionCheck=1;
	if(DeathCheck>-1)
	DeathCheck--;
	dx1=420;dx2=460;dx3=440;
		dy1=50;dy2=50;dy3=100;
}
