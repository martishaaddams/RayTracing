//#pragma once
#ifndef BOX_H
#define BOX_H
#include "Figure.h"
#include <iostream>
#include <array>
#include <cstdint>
class box : public Figure
{
public:
	std::array<float, 3> min_point ;
	std::array<float, 3> max_point;
	sf::Color color;
	bool Intersect(Ray &r);
	box();

	//~box();
};
#endif // !BOX_H



