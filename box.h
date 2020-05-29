//#pragma once
#ifndef BOX_H
#define BOX_H
#include "Figure.h"
#include <iostream>
#include <array>
class box : public Figure
{
public:
	std::array<int, 3> min_point ;
	std::array<int, 3> max_point;
	bool Intersect(Ray &r);
	box();

	~box();
};
#endif // !BOX_H



