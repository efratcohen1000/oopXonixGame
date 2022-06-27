#pragma once
#include "collide.h"
#include "MoveBehavior.h"
#include <SFML/Graphics.hpp>
class SmartMoveBehavior :
	public MoveBehavior
{
public:
	//Algorithm of moving enemies
	//The wise enemy is in enemy territory
	void Move(sf::Vector2f pos, sf::Sprite& sprite, sf::Vector2f posPlayer, std::vector < std::vector<Rec>> board)
	{
		sf::Vector2f po = pos;
		int numrun;
		srand(unsigned( time(NULL)));
		numrun = rand() % 4;
		if (numrun % 2 == 0)
		{
			if (pos.x < posPlayer.x)
				po.x+=40;
			else
				po.x-= 40;
		}
		else
		{
			if (pos.y < posPlayer.y)
				po.y+= 40;
			else
				po.y-= 40;
		}
		//Checking what kind of terrain is moving
		for (int k = 0; k < 20; k++)
			for (int j = 0; j < 20; j++)
				if (board[k][j].getPos() ==  po)
					if (board[k][j].getState() == ENEMYSPACE || board[k][j].getState() == INRUN)
					{
						sprite.setPosition(po);
					}
	}
};

