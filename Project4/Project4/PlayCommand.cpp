#include "PlayCommand.h"
//Set up an entry button
PlayCommand::PlayCommand(sf::Font& font, const sf::Vector2f pos)
{
	m_text.setFont(font);
	m_text.setCharacterSize(55);
	m_text.setPosition(pos);
	m_text.setFillColor(sf::Color::Cyan);
	m_text.setOutlineColor(sf::Color::Red);
	m_text.setOutlineThickness(4);
	m_text.setString("PLAY");
}
