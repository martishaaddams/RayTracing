#ifndef RAY_H
#define RAY_H
#include <iostream>
#include <array>
class Ray
{
public:
	std::array<int, 3> direction;
	std::array<int, 3> dot;
	float t=INFINITY;
	Ray();
	Ray(std::array<int,3> a, std::array<int, 3> b);
	Ray(std::array<int,6> a);
	void out();
	~Ray() {};

};
#endif

