#pragma once
#include "Rec.h"
#include <ctime>
#include <dos.h>
#include <vector>
#include "Board.h"
#include <iostream>
#include "Player.h"
#include "Screen.h"
#include <Windows.h>
#include "collide.h"
#include "Command.h"
#include "PlayCommand.h"
#include "ExitCommand.h"
#include "ResourceManager.h"
#include "CollisionHandling.h"
#include <SFML/Graphics.hpp>
class Controller
{
public:
	void draw();
	Controller();
	void start();
	~Controller() {};
	void collide();
	void checkEnd();
	static int m_numLevel;
	void checkAndMove(sf::Vector2f& pos, sf::Vector2f& d);
	void eventReact(sf::Event event, sf::Vector2f& d, sf::Vector2f& pos);
private:
	Board m_board;
	Screen m_screen;
	std::unique_ptr<Player> m_player;
	sf::Vector2f m_posPlayer;
	sf::RenderWindow m_window;
	std::vector<sf::Vector2i> m_indexRun;
};