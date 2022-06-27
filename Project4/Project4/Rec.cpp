#include "Rec.h"
//Slots of the board have three modes, enemy space and player space during runtime
Rec::Rec(sf::Vector2f pos, const sf::Vector2f sizeOfTexture, MyEnum r) :
	m_state(r), StaticObjects(pos)
{
	m_rec.rotate(45);
	switch (r)
	{
	case PLAYERSPACE:
		m_sprite.setTexture(ResourceManager::instance().getPicture("PLAYERSPACE"));
		break;
	case ENEMYSPACE:
		m_sprite.setTexture(ResourceManager::instance().getPicture("ENEMYSPACE"));
		break;
	default:
		break;
	}
	m_sprite.scale(sizeOfTexture.x / m_sprite.getGlobalBounds().width, sizeOfTexture.y / m_sprite.getGlobalBounds().height);
	m_sprite.setPosition(pos);
}

void Rec::setPos(float x, float y)
{
	m_rec.setPosition({ x,y });
}

sf::Vector2f Rec::getPos()
{
	return m_sprite.getPosition();
}

void Rec::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//בזמן ריצה
void Rec::setStateUser(MyEnum r)
{
	if (m_state != PLAYERSPACE)
	{
		m_state = r;
		switch (r)
		{
		case INRUN:
			m_sprite.setTexture(ResourceManager::instance().getPicture("INRUN"));
			break;
		case PLAYERSPACE:
			m_sprite.setTexture(ResourceManager::instance().getPicture("PLAYERSPACE"));
			break;
		case ENEMYSPACE:
			m_sprite.setTexture(ResourceManager::instance().getPicture("ENEMYSPACE"));
			break;
		default:
			break;
		}
	}
}

MyEnum Rec::getState()
{
	return m_state;
}

sf::Color Rec::getColor()
{
	return m_rec.getFillColor();
}
