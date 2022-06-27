#include "Controller.h"
#include <iostream>
#include <stdio.h>
using std::cout;

const int LEVEL = 4;
int Controller::m_numLevel = 1;
const int numrows = 20, numcols = 20;
//איתחול המשחק
Controller::Controller()
	:m_window(sf::VideoMode(1000, 900), "xonix"), m_screen(), m_board(), m_posPlayer({ 0, 0 }), m_indexRun(), m_player(nullptr)
{
	if (m_screen.isNoClose())
	{
		m_screen.actCommand(m_window, 0);
		ResourceManager::instance().getMusic("gameMusic")->play();
		m_board.loadBoard(m_window);
		m_player = std::make_unique<Player>(m_board.setPosPicture({ 0,0 }));
		m_player->setLives(5);
		m_screen.menuShow(m_window, m_numLevel, m_player->getLives());
		start();
	}
	m_screen.actCommand(m_window, 1);
}
//תחילת המשחק הפונקציה הראשית
void Controller::start()
{
	m_board.moveEnemy(m_player->getPos());
	sf::Vector2f d(0, 0), pos = m_player->getPos();
	sf::Event event;
	while (m_window.isOpen() && m_player->getLives() > 0)
	{
		while (m_window.pollEvent(event))
			eventReact(event, d, pos);
		draw();
	}
	m_screen.end(m_window);
}
//פונקציית הדפסה
void Controller::draw()
{
	checkEnd();
	m_window.clear();
	m_board.draw(m_window);
	m_board.moveEnemy(m_player->getPos());
	m_screen.menuShow(m_window, m_numLevel, m_player->getLives());
	m_window.draw(m_player->getObject());
	m_window.display();
}
//בדיקות ותזוזה
void Controller::checkAndMove(sf::Vector2f& pos, sf::Vector2f& d)
{
	if (m_player->getPosInBoard().x + d.x >= 0 && m_player->getPosInBoard().y + d.y >= 0 && m_player->getPosInBoard().x + d.x < 20 && m_player->getPosInBoard().y + d.y < 20)
	{
		if (m_board.getStateRec({ int(m_player->getPosInBoard().x + d.x), int(m_player->getPosInBoard().y + d.y) }) == PLAYERSPACE)
		{
			for (int i = 0; i < m_indexRun.size(); i++)
				m_board.setRec({ m_indexRun[i] }, PLAYERSPACE);
			m_indexRun.clear();
		}
		m_player->colideRec(m_board.getStateRec({ int(m_player->getPosInBoard().x + d.x), int(m_player->getPosInBoard().y + d.y) }));
		m_player->setPos({ m_board.setPosPicture({ m_player->getPosInBoard().x + d.x, m_player->getPosInBoard().y + d.y }) });
		m_indexRun.push_back({ int(m_player->getPosInBoard().x + d.x), int(m_player->getPosInBoard().y + d.y) });
		m_player->setPosInBoard({ int(m_player->getPosInBoard().x + d.x), int(m_player->getPosInBoard().y + d.y) });
		m_board.setRec({ int(m_player->getPosInBoard().x), int(m_player->getPosInBoard().y) }, INRUN);
		collide();
	}
	
}
//בדיקת הלחיצות ולפי זה התזוזה
void Controller::eventReact(sf::Event event, sf::Vector2f& d, sf::Vector2f& pos)
{
	if (event.type == sf::Event::Closed)
		m_window.close();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		d = m_player->act(event, pos);
		checkAndMove(pos, d);
	}
}

void Controller::collide()
{
	auto& player = m_player;
	for (int i = 0; i < m_board.getSizeVecEnemy(); i++)
	{
		if (collideObjects(*player, m_board.giveEnemy(i)))
			processCollision(*player, m_board.giveEnemy(i));
	}
	for (int i = 0; i < numrows; i++)
		for (int j = 0; j < numcols; j++)
			if (collideObjects(*player, m_board.giveRec(i, j)))
				processCollision(*player, m_board.giveRec(i, j));
	for (int i = 0; i < m_board.giveSizeVecGift(); i++)
		if (collideObjects(*player, *m_board.giveGift(i)))
			processCollision(*player, *m_board.giveGift(i));
}
//בודק אם השחקן סיים לכבוש את כל המשבצות
void Controller::checkEnd()
{
	bool levelOver = true;
	for (int i = 0; i < numrows; i++)
		for (int j = 0; j < numcols; j++)
			if (m_board.giveRec(i, j).getState() == ENEMYSPACE )
			{
				levelOver = false;
				return;
			}
	if (levelOver)
	{
		m_board.newLevel();
		m_board.loadBoard(m_window);
	}
	
}