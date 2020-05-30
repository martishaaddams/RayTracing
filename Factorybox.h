#pragma once
#include "Figure.h"
#include "box.h"
#include "Header.h"
class Factorybox:Factory
{
public: 
    box* create()const
    {
        return new box;
    }

};
