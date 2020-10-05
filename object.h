/*
 * object.h
 *
 *  Created on: May 10, 2018
 *      Author: mueed
 */
#include<cstdlib>
#include"util.h"

#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

#ifndef OBJECT_H_
#define OBJECT_H_

class object
{

public:
	object();
	void display();
	~object();
};

#endif /* OBJECT_H_ */
