//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Brick Slayer...
//============================================================================

#ifndef AsteroidS_CPP_
#define AsteroidS_CPP_
#include<cstdlib>
#include"util.h"
#include"myAsteroid.h"
#include"level.h"
#include"enemy.h"
#include"Bullet.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;


// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}



//Number of Vertices used to draw Bomberman Circle...
// x= r cos (theta), y= r sin(theta)
const int npmvertices = 1220;
GLfloat pmvertices[npmvertices][2];
void InitPMVertices(float radius) {

	float hdegree = (M_PI - M_PI / 2.0) / 360.0;
	float angle = M_PI + M_PI / 6.0;
	for (int i = 0; i < npmvertices; ++i) {
		pmvertices[i][0] = radius * cos(angle);
		pmvertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}
}

void DrawBomberman(float sx/*center x*/, float sy/*center y*/,
		float radius/*Radius*/,
		const ColorNames &colorname/*Bomberman Colour*/) {

	glColor3fv(colors[colorname]); // set the circle color
	InitPMVertices(radius);
	glBegin (GL_TRIANGLE_FAN);
	glVertex4f(sx, sy, 0, 1);
	for (int i = 0; i < npmvertices; ++i)
		glVertex4f(sx + pmvertices[i][0], sy + pmvertices[i][1], 0, 1);
	glEnd();
	DrawCircle(sx - radius + radius / 2, sy + (radius - radius / 2),
			radius / 10, colors[BLACK]);
}
/*
 * Main Canvas drawing function.
 * */
bool checkCollision(int bx,int by,int astx,int asty)// to check collision
{
	if(	sqrt((astx-bx)*(astx-bx)+(asty-by)*(asty-by))<(0.8*50)	)
		{
			//this->astCount++;
			//cout<<"bx "<<bx<<" by "<<by<<" astx "<<astx<<" asty "<<asty<<endl;
			return 1;
		}
	else
		return 0;
}

Board *b;
int x, y;
gameObjects alpha;
int gamePause=1;// to pause game upon shooter destruction
level myLevel;// to control level
myAsteroid *ast = new myAsteroid[500];// array of asteroids
myShip Captain;//my shooter
enemy alien[4];
Bullet *myBullet=new Bullet[1000];//my Bullets for shooter,
int BulletCount=0;//Counts amount of bullets to shoot


void GameDisplay()/**/
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// draw four asteroids
	/*b->Draw();
	int x, y;
	b->GetInitRandomPosition(x, y);*/

	for(int i=myLevel.getLevel()-1;i<myLevel.getAsteroidCount() && Captain.getDeathCount()>0;i++)
	{
		ast[i].display();

		if(checkCollision(Captain.get_dx3(),Captain.get_dy3(),ast[i].getX(),ast[i].getY())==1)
		{
			Captain.destroy();
			gamePause=0;
			DrawString(400,400,"You Lost 1 life", colors[5]);
			DrawString(400,300,"Press 'o' to continue", colors[5]);
		}
		for(int j=0;j<BulletCount;j++)
			{

					myBullet[j].display();
					if(checkCollision(myBullet[j].getX(),myBullet[j].getY(),ast[i].getX(),ast[i].getY())==1 || checkCollision(myBullet[j].getX()-20,myBullet[j].getY()-50,ast[i].getX(),ast[i].getY())==1 || checkCollision(myBullet[j].getX()+20,myBullet[j].getY()+50,ast[i].getX(),ast[i].getY())==1)
					{
					ast[i].destroy();
					myLevel.plusScore();
					myBullet[j].setCheck(-1);
					}
			}
	}
	for(int i=0;i<4;i++)
	{for(int j=0;j<BulletCount;j++)
		if(checkCollision(myBullet[j].getX(),myBullet[j].getY(),alien[i].get_dx3(),alien[i].get_dy3())==1)
		{
		alien[i].destroy();
		myLevel.plusScore();
		myBullet[j].setCheck(-1);

		}

	}
	if(Captain.getDeathCount()>0)
	{
		if(gamePause==1)
		Captain.display();
		for(int i=0;i<4;i++)
		alien[i].display();
string temp=Num2Str(myLevel.getScore());
		DrawString(80, 800,"Score = ", colors[5]);
		DrawString(160, 800,temp, colors[5]);
		temp=Num2Str(myLevel.getLevel());
		DrawString(200, 800,"Level = ", colors[5]);
		DrawString(280, 800,temp, colors[5]);

		temp=Num2Str(Captain.getDeathCount());
		DrawString(400, 800,"Lives = ", colors[5]);
				DrawString(480, 800,temp, colors[5]);
}
else
{
	string temp=Num2Str(myLevel.getScore());
			DrawString(200, 500,"Score = ", colors[5]);
			DrawString(280, 500,temp, colors[5]);
			temp=Num2Str(myLevel.getLevel());
			DrawString(200, 600,"Level = ", colors[5]);
			DrawString(280, 600,temp, colors[5]);
			DrawString(400,400,"Game Over", colors[5]);
}


	if(gamePause==0 && Captain.getDeathCount()>0)
		{
			DrawString(400,400,"You Lost 1 life", colors[5]);
						DrawString(400,300,"Press 'o' to continue", colors[5]);
		}
	//b->GetInitTextPosition(x, y);
		//cout << endl <<"Text Position = "<< x << "  y= " << y << endl << flush;


//DrawString(40, 800,to_string(myLevel.getScore()), colors[5]);

//b->GetInitBombermanPosition(x, y);
//DrawBomberman(x, y, b->GetCellSize() / 2 - 2, YELLOW);
	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y)
{
	 if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	{
		// what to do when left key is pressed...
		 Captain.shipMover(50,0,0,0);
		//Captain.shipRotate();

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		Captain.shipMover(0,50,0,0);
		//Captain.shipRotate();
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		Captain.shipMover(0,0,50,0);
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		Captain.shipMover(0,0,00,50);
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	/*
	 glutPostRedisplay();
	 */
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y)
{
	if (key == 27/* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B' ) //Key for placing the bomb
	{
		if(BulletCount%200==0)
					BulletCount=0;
		myBullet[BulletCount].setCheck(1);

			myBullet[BulletCount].makeBullet(Captain.get_dx3(),Captain.get_dy3());
		BulletCount++;

	}
	if (key == 'p' || key == 'P')
	{
		////do something if p is pressed
			gamePause=0;

	}
	if (key == 'o' || key == 'O')
		{
			////do something if p is pressed
				gamePause=1;
		}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
int timerX=100,timerY=100;
void Timer(int m)
{

	// implement your functionality here
	if(gamePause==1)
	{
			for(int i=0;i<myLevel.getAsteroidCount();i++)
				{
				ast[i].pixelMover();
				}
			for(int i=0;i<BulletCount;i++)
				{
					myBullet[i].pixelMover();
				}
	}


	glutPostRedisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(myLevel.getFps(), Timer, 0);
}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	InitRandomizer(); // seed the random number generator...
	for(int i = 0 ;i<500;i++)
	{
		ast[i].xySetter(GetRandInRange(0,1020),GetRandInRange(400,840));
	}

	b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("mueed i17-0132 Asteroid Game"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
#ifdef WITH_TEXTURES
	RegisterTextures();
#endif
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
