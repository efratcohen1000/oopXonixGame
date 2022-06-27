#pragma once
#include "Rec.h"
#include <time.h>
#include <stdlib.h>
#include "collide.h"
#include "MoveBehavior.h"
#include <SFML/Graphics.hpp>
class ForwardMoveBehavior :
	public MoveBehavior
{
public:
	//Random displacement algorithm
	//The smart enemy is in the player's territory
	void Move(sf::Vector2f pos, sf::Sprite& sprite, sf::Vector2f posPlayer, std::vector < std::vector<Rec>> board)
	{
		sf::Vector2f m_d = { 0, 0 };
		int numrun;
		numrun = rand() % 4;
		switch (numrun)
		{
		case 0:
			m_d.y = 40;
			break;
		case 1:
			m_d.y = -40;
			break;
		case 2:
			m_d.x = 40;
			break;
		case 3:
			m_d.x = -40;
			break;
		}
		//Checking what kind of terrain is moving
		for (int k = 0; k < 20; k++)
			for (int j = 0; j < 20; j++)
				if (board[k][j].getPos() == m_d + pos)
					if (board[k][j].getState() == PLAYERSPACE)
						sprite.setPosition(m_d + pos);
	}
};

