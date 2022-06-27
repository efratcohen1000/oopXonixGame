#pragma once
#include "Rec.h"
#include <string>
#include <time.h>
#include "Enemy.h"
#include <iomanip>
#include <fstream>
#include <ostream>
#include <stdlib.h>
#include <iostream>
#include "collide.h"
#include "ImmuneGift.h"
#include "MoveBehavior.h"
#include "EatEnemyGift.h"
#include "StaticObjects.h"
#include "ResourceManager.h"
#include "SmartMoveBehavior.h"
#include "ForwardMoveBehavior.h"
#include <SFML/Graphics.hpp>
class Board
{
public:
	Board();
	 ~Board();
	int getSizeVecEnemy();
	Enemy& giveEnemy(int i);
	Rec& giveRec(int i, int j);
	void draw(sf::RenderWindow& window);
	MyEnum getStateRec(sf::Vector2i index);
	void moveEnemy(sf::Vector2f posPlayer);
	void loadBoard(sf::RenderWindow& window);
	void setRec(sf::Vector2i index, MyEnum r);
	sf::Vector2f setPosPicture(sf::Vector2f pos);
	void boardInitialization(char c, int i, int j);
	void newLevel();
	std::shared_ptr<StaticObjects>& giveGift(int i) { return m_staticObjects[i]; };
	int giveSizeVecGift() { return m_staticObjects.size(); }
private:
	int m_size;
	int m_level;
	sf::Sprite m_sprite;
	std::ifstream m_file;
	sf::Texture m_background;
	sf::Vector2f m_sizeOfRec;
	std::vector < std::vector<Rec>> m_board;
	std::vector<std::shared_ptr<Enemy>> m_enemy;
	std::vector<std::shared_ptr<StaticObjects>> m_staticObjects;
};

