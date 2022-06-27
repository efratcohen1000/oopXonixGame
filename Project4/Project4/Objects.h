#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
class Objects
{
public:
	virtual ~Objects() { };
	Objects(sf::Vector2f pos) {};
	void setObject(sf::Sprite sprite) {  m_sprite = sprite; }
	sf::Sprite getObject() const {return m_sprite;}
protected:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

