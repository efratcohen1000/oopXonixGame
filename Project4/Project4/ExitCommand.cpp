#include "ExitCommand.h"
//Set the exit button
ExitCommand::ExitCommand(sf::Font& font, const sf::Vector2f pos)
{
	m_text.setFont(font);
	m_text.setCharacterSize(55);
	m_text.setPosition(pos);
	m_text.setFillColor(sf::Color::Cyan);
	m_text.setOutlineColor(sf::Color::Red);
	m_text.setOutlineThickness(4);
	m_text.setString("EXIT");
}