#include "EatEnemyGift.h"
//מתנה שגורמת לשחקן לאכול אויבים

EatEnemyGift::EatEnemyGift(bool state, sf::Vector2f pos) :Gift(state, pos)
{
	m_texture = ResourceManager::instance().getPicture("eatEnemyGift");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(pos);
}