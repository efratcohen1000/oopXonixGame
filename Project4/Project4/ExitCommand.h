#pragma once
#include "Command.h"
class ExitCommand :
	public Command
{
public:
	~ExitCommand() {};
	void act(sf::RenderWindow& window) { window.close(); };
	ExitCommand(sf::Font& font, const sf::Vector2f pos);
};

