#pragma once
#include "Board.h"
#include "Command.h"
class PlayCommand :
	public Command
{
public:
	~PlayCommand() {};
	void act(sf::RenderWindow& window) {};
	PlayCommand(sf::Font& font, const sf::Vector2f pos);
};

