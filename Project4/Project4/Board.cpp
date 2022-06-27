#include "Board.h"
using std::cerr;
using std::ifstream;
using std::fstream;
//מספר שורות מספר עמודות
const int numrows = 20, numcols = 20;
//מאתחל את המשחק
Board::Board() :m_level(1)
{
	m_background = ResourceManager::instance().getPicture("background");
	m_sprite.setTexture(m_background);
	try { m_file.open("Level.txt"); } //exception
	catch(std::exception& e)
	{ 
		if (!m_file.is_open())
			cerr << "The file failed to open" << std::endl;
	}
	m_sizeOfRec = { float(800 / numcols) ,float((800) / numrows) };
	m_board.resize(numrows);
	//המטריצה של הריבועים
	for (int i = 0; i < numrows; i++)
		for (int j = 0; j < numcols; j++)
		{
			if (i == 0 || i == numrows - 1 || j == 0 || j == numcols - 1)
				m_board[j].push_back(Rec{ sf::Vector2f{ (float)j * m_sizeOfRec.x + 100,(float)i * m_sizeOfRec.y + 50 }, m_sizeOfRec,PLAYERSPACE });
			else
				m_board[j].push_back(Rec{ sf::Vector2f{ (float)j * m_sizeOfRec.x + 100,(float)i * m_sizeOfRec.y + 50 }, m_sizeOfRec,ENEMYSPACE });
		}
}

Board::~Board()
{
}
//מטעין את הלוח לפי הקובץ
void Board::loadBoard(sf::RenderWindow& window)
{
	if (m_file.is_open())
	{
		char c;
		for (int i = 0; i < numrows; i++)
			for (int j = 0; j <= numcols; j++)
			{
				c = m_file.get();
				if (c == '\n') { break; }
				boardInitialization(c, i, j);
			}
	}
}

sf::Vector2f Board::setPosPicture(sf::Vector2f pos)
{
	return m_board[int(pos.y)][int(pos.x)].getPos();
}
//הדפסת הלוח והאובייקטים
void Board::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	for (unsigned int i = 0; i < m_board.size(); i++)
		for (unsigned int j = 0; j < m_board[i].size(); j++)
		{
			m_board[i][j].draw(window);
		}
	for (unsigned int i = 0; i < m_staticObjects.size(); i++)
		window.draw(m_staticObjects[i]->getObject());
	for (auto &a : m_enemy)
		window.draw(a->getObject());
}
//שם מצב הריבוע של הלוח
void Board::setRec(sf::Vector2i index, MyEnum r)
{
	m_board[index.y][index.x].setStateUser(r);
}
//מביא את מצב המשבצת של הלוח
MyEnum Board::getStateRec(sf::Vector2i index)
{
	return m_board[index.y][index.x].getState();
}
//גודל ווקטור של האויבים
int Board::getSizeVecEnemy()
{
	return m_enemy.size();
}
//משתמש באסטרטגיה של התזוזה
void Board::moveEnemy(sf::Vector2f posPlayer)
{
	for (int i = 0; i < m_enemy.size(); i++)
		m_enemy[i]->PerformMove(posPlayer, m_board);
}
//מביא אויב ספציפי
Enemy& Board::giveEnemy(int i)
{
	return *(m_enemy[i]);
}

//מביא משבצת ספציפית מהלוח
Rec& Board::giveRec(int i, int j)
{
	return m_board[i][j];
}
//מכניס ערכים לווקטורים
void Board::boardInitialization(char c, int i, int j)
{
	switch (c)
	{
	case '4'://מטבע
	{
		m_staticObjects.push_back(std::make_shared<ImmuneGift>(0, sf::Vector2f{ (float)j * m_sizeOfRec.x + 100, (float)i * m_sizeOfRec.y + 50 }));
		break;
	}
	case '5'://מתנה
	{
		m_staticObjects.push_back(std::make_shared<EatEnemyGift>(1, sf::Vector2f{ (float)j * m_sizeOfRec.x + 100, (float)i * m_sizeOfRec.y + 50 }));
		break;
	}
	case '6'://enemy
	{
		sf::Vector2f pos = sf::Vector2f{ (float)j * m_sizeOfRec.x + 100, (float)i * m_sizeOfRec.y + 50 };
		m_enemy.emplace_back(std::make_shared<Enemy>(pos, std::make_unique<ForwardMoveBehavior>()));
		break;
	}
	case '7'://enemy smart
	{
		sf::Vector2f pos = sf::Vector2f{ (float)j * m_sizeOfRec.x + 100, (float)i * m_sizeOfRec.y + 50 };
		m_enemy.emplace_back(std::make_shared<Enemy>(pos, std::make_unique<SmartMoveBehavior>()));
		break;
	}
	default:
		break;
	}


}
//שלב חדש
void Board::newLevel()
{
	for (int i = 0; i < numrows; i++)
		for (int j = 0; j < numcols; j++)
		{
			if (i == 0 || i == numrows - 1 || j == 0 || j == numcols - 1)
				m_board[j][i].setState(PLAYERSPACE);
			else
				m_board[j][i].setState(ENEMYSPACE);
		}
}
