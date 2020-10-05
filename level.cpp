

#include "level.h"
#include"cstring"

level::level()
{
this->levelCount=1;
this->score=0;
this->fps=60;
this->astCount=6;
}
void level::plusScore()
{				this->score+=1;
				if(score==astCount)
					{
					this->levelCount++;
					this->astCount+=6+levelCount;
					this->fps-=5;
					}
}
int level::getScore()const
{
	return score;
}
int level::getLevel()const
{
	return levelCount;
}
int level::getFps()const
{
	return this->fps;
}
