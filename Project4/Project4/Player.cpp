#include "Player.h"

Player::~Player()
{
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//תזוזת כיוון השחקן
sf::Vector2f Player::act(sf::Event e, sf::Vector2f& pos)
{
	sf::Vector2f direct(0, 0);
	bool crash = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direct = { -1,0 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direct = { 1, 0 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direct = { 0, 1 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direct = { 0, -1 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		direct = { 0,0 };
	}
	return direct;
}

sf::Vector2f Player::getPos()
{
	return m_sprite.getPosition();
}
//מיקום על הלוח 
sf::Vector2i Player::getPosInBoard()
{
	return m_index;
}
//מיקום בפיקסלים
void Player::setPos(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}
//בתזוזה שלו 
MyEnum Player::colideRec(MyEnum r)
{
	return INRUN;
}
//הגדרת השחקן
Player::Player(sf::Vector2f pos): MoveObjects(pos), m_index({0,0})
{
	m_texture = ResourceManager::instance().getPicture("player");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition({ pos.x, pos.y});
}
