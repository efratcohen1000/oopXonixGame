#pragma once
#include "Rec.h"
#include "MoveObjects.h"
#include "MoveBehavior.h"
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
class Enemy :
	public MoveObjects
{
public:
	virtual ~Enemy() {};
	virtual void Display() {};
	void draw(sf::RenderWindow& window);
	void PerformMove(sf::Vector2f posPlayer, std::vector < std::vector<Rec>> board);
	void SetMoveBehavior(std::unique_ptr<MoveBehavior>	pMoveBehavior)
	{
		m_pMoveBehavior = move(pMoveBehavior);
	}
	sf::Vector2f getPos() { m_sprite.getPosition(); }
	Enemy(sf::Vector2f pos, std::unique_ptr<MoveBehavior>	pMoveBehavior);
private:
	std::unique_ptr<MoveBehavior>	m_pMoveBehavior;

};

