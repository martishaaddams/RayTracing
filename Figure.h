//#pragma once
#ifndef Figure_H
#define Figure_H
#include"Ray.h"
#include <iostream>
class Figure
{
public:
	//virtual Figure()=0;
	virtual bool Intersect(Ray &r)=0;
	//virtual~Figure()=0;
};

#endif