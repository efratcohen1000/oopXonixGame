#pragma once
#include "Gift.h"
#include "ResourceManager.h"
class EatEnemyGift :
	public Gift
{
public:
	EatEnemyGift(bool state, sf::Vector2f pos = { 0,0 });
	virtual ~EatEnemyGift() {};
};

