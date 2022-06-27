#pragma once
#include "ResourceManager.h"
#ifdef _DEBUG
#pragma comment(lib, "sfml-main-d.lib")
#elif defined(NDEBUG)
#pragma comment(lib, "sfml-main.lib")
#else
#error "Unrecognized configuration!"
#endif
#include <SFML/Graphics.hpp>
#include "PlayCommand.h"
#include "ExitCommand.h"
#include "Command.h"
class Screen
{
public:
	Screen();
	~Screen() {};
	bool isNoClose();
	void end(sf::RenderWindow& window);
	void menuShow(sf::RenderWindow& window, int level, int life);
	void showScore(sf::RenderWindow& window);
	void buttonDraw(sf::RenderWindow& window);
	void actCommand(sf::RenderWindow& window, int i);
private:
	sf::Text m_text;
	sf::Font m_font;
	bool m_isNoClose;
	sf::Sprite m_image;
	sf::Texture m_texture;
	sf::Sprite m_image_button;
	std::vector<std::unique_ptr<Command>> m_command;
};

