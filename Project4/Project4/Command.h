#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
//button
class Command
{
public:
	Command() {};
	~Command() {};
	virtual void act(sf::RenderWindow& window) = 0;
	virtual void draw(sf::RenderWindow& window) { window.draw(m_text); };
protected:
	sf::Font m_font;
	sf::Text m_text;
};

