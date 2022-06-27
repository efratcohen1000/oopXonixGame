#pragma once
#include "Gift.h"
#include "ResourceManager.h"
class ImmuneGift :
	public Gift
{
public:
	ImmuneGift(bool state, sf::Vector2f pos = { 0,0 });
	virtual ~ImmuneGift() {};

};

