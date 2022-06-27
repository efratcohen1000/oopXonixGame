#include "Enemy.h"
//הגדרת האויב
Enemy::Enemy(sf::Vector2f pos, std::unique_ptr<MoveBehavior>	pMoveBehavior)
	:MoveObjects(pos)
{
	m_pMoveBehavior = std::move(pMoveBehavior);
	m_texture = ResourceManager::instance().getPicture("enemy");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition({ pos.x, pos.y });
	m_sprite.setScale({float( 0.7 ),float( 0.7 ) });
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//שימוש באסטרטגיה
void Enemy::PerformMove(sf::Vector2f posPlayer, std::vector < std::vector<Rec>> board)
{
	m_pMoveBehavior->Move(m_sprite.getPosition(), m_sprite, posPlayer, board);
}

