#pragma once
#include "Figure.h"
#include "box.h"
class Factory
{
public:
	virtual Figure* create( ) const = 0;
};