#include "Board.h"
using std::cerr;
using std::ifstream;
using std::fstream;
//���� ����� ���� ������
const int numrows = 20, numcols = 20;
//����� �� �����
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
	//������� �� ��������
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
//����� �� ���� ��� �����
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
//����� ���� �����������
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
//�� ��� ������ �� ����
void Board::setRec(sf::Vector2i index, MyEnum r)
{
	m_board[index.y][index.x].setStateUser(r);
}
//���� �� ��� ������ �� ����
MyEnum Board::getStateRec(sf::Vector2i index)
{
	return m_board[index.y][index.x].getState();
}
//���� ������ �� �������
int Board::getSizeVecEnemy()
{
	return m_enemy.size();
}
//����� ��������� �� ������
void Board::moveEnemy(sf::Vector2f posPlayer)
{
	for (int i = 0; i < m_enemy.size(); i++)
		m_enemy[i]->PerformMove(posPlayer, m_board);
}
//���� ���� ������
Enemy& Board::giveEnemy(int i)
{
	return *(m_enemy[i]);
}

//���� ����� ������� �����
Rec& Board::giveRec(int i, int j)
{
	return m_board[i][j];
}
//����� ����� ���������
void Board::boardInitialization(char c, int i, int j)
{
	switch (c)
	{
	case '4'://����
	{
		m_staticObjects.push_back(std::make_shared<ImmuneGift>(0, sf::Vector2f{ (float)j * m_sizeOfRec.x + 100, (float)i * m_sizeOfRec.y + 50 }));
		break;
	}
	case '5'://����
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
//��� ���
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
