/*
 * enemyBullet.h
 *
 *  Created on: May 10, 2018
 *      Author: mueed
 */

#ifndef ENEMYBULLET_H_
#define ENEMYBULLET_H_
#include"Bullet.h"
class enemyBullet:public Bullet
{
public:
	enemyBullet();
	void pixelMover();
	virtual ~enemyBullet();
};

#endif /* ENEMYBULLET_H_ */
