#pragma once
#include "StaticObjects.h"
#include "ResourceManager.h"
enum MyEnum
{
	INRUN, PLAYERSPACE, ENEMYSPACE
};
class Rec :
	public StaticObjects
{
public:
	virtual ~Rec() {};
	MyEnum getState();
	sf::Color getColor();
	sf::Vector2f getPos();
	void setStateUser(MyEnum r);
	void setPos(float x, float y);
	void draw(sf::RenderWindow& window);
	void setState(MyEnum r) { m_state = r; }
	Rec(sf::Vector2f pos, const sf::Vector2f sizeOfTexture, MyEnum r);
private:
	MyEnum m_state;
	sf::RectangleShape m_rec;
};

