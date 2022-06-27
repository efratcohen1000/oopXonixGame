#pragma once
#include "Rec.h"
class enemy;
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
class MoveBehavior
{
public:
	//Movement algorithms
	virtual void Move(sf::Vector2f pos, sf::Sprite& sprite, sf::Vector2f posPlayer, std::vector < std::vector<Rec>> board) = 0;
};

