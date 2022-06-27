#include "Screen.h"

Screen::Screen() :
	m_isNoClose(true)
{
	//הגדרת מסך פתיחה
	m_texture = ResourceManager::instance().getPicture("screenOpen");
	m_font = ResourceManager::instance().getText("sansation");
	m_image.setTexture(m_texture);
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Xonix");
	//הגדרת הכפתורים
	m_command.emplace_back(std::make_unique<PlayCommand>(m_font, sf::Vector2f{ window.getSize().x / float(2) - 55, window.getSize().y / (2) * float(1) }));
	m_command.emplace_back(std::make_unique<ExitCommand>(m_font, sf::Vector2f{ window.getSize().x / float(2) - 50, window.getSize().y / (2) * float(1.5) - 55}));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
			//אם לחץ על לחץ  התחלת משחק
			if (mousePosition.x <= window.getSize().x / float(2) +100 && mousePosition.x >= window.getSize().x / float(2) - 55
				&& mousePosition.y <= window.getSize().y / (2) * float(1) + 55 && mousePosition.y >= window.getSize().y / (2) * float(1))
			{
				window.clear();
				window.close();

			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
				m_isNoClose = false;
			}
			//אם סגר את המשחק
			if (mousePosition.x <= (window.getSize().x / float(2) + 70) && mousePosition.x >= (window.getSize().x / float(2) - 50)
				&& mousePosition.y <=( window.getSize().y / (2) * float(1.5) + 55) && mousePosition.y >= window.getSize().y / (2) * float(1.5) - 55)
			{
				window.close();
				m_isNoClose = false;

			}
		}

		window.clear();
		window.draw(m_image);
		buttonDraw(window);
		window.display();
	}

}

bool Screen::isNoClose()
{
	return m_isNoClose;
}
//מסך סיום
void Screen::end(sf::RenderWindow& window)
{
	window.clear();
	m_texture = ResourceManager::instance().getPicture("gameOver");
	m_image.setTexture(m_texture);
	m_image.scale(4, 4);
	window.draw(m_image);
	window.display();
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))//waits for a press
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))//if pressed to exit
		{
			return;
		}
	}
}
//תפריט מראה חיים ושלב
void Screen::menuShow(sf::RenderWindow& windowPlay, int level, int life)
{
	m_text.setFont(m_font);
	m_text.setCharacterSize(40);
	m_text.setPosition(100, 0);
	m_text.setFillColor(sf::Color::White);

	m_text.setString("Level: " + std::to_string(level) + "   Life:  " + std::to_string(life));
	windowPlay.draw(m_text);
}

void Screen::showScore(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void Screen::buttonDraw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_command.size(); i++)
		m_command[i]->draw(window);
}
//הפעולה של הכפתורים
void Screen::actCommand(sf::RenderWindow& window, int i)
{
	return m_command[i]->act(window);
}