#include "ImmuneGift.h"

ImmuneGift::ImmuneGift(bool state, sf::Vector2f pos) :Gift(state, pos)
{
	m_texture = ResourceManager::instance().getPicture("immuneGift");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(pos);
}
