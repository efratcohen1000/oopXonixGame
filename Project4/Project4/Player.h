#pragma once
#include "Rec.h"
#include "Enemy.h"
#include "Board.h"
#include "MoveObjects.h"
#include "StaticObjects.h"
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
class Controller;
class Player :
	public MoveObjects
{
public:
	virtual ~Player();
	sf::Vector2f getPos();
	void downLive() { m_live--; };
	MyEnum colideRec(MyEnum r);
	sf::Vector2i getPosInBoard();
	void setPos(sf::Vector2f pos);
	Player(sf::Vector2f pos={0,0});
	void draw(sf::RenderWindow& window);
	int getLives() const { return m_live; };
	void setLives(int live) { m_live = live; };
	sf::Vector2f act(sf::Event e, sf::Vector2f& pos);
	void setPosInBoard(sf::Vector2i pos) { m_index = pos; };
private:
	int m_live;
	sf::Vector2i m_index;
};

