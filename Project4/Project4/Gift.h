#pragma once
#include "StaticObjects.h"
class Gift :
	public StaticObjects
{
public:
	virtual ~Gift() { };
	Gift(bool state, sf::Vector2f pos = { 0,0 });
};

