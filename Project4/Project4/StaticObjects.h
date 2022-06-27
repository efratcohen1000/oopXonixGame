#pragma once
#include "Objects.h"
class StaticObjects :
	public Objects
{
public:
	virtual ~StaticObjects() {};
	StaticObjects(sf::Vector2f pos);
};

