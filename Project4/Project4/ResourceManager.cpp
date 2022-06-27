#include "ResourceManager.h"
//הגדרת המיפוי של התמונות המוזיקה והטקסט
ResourceManager::ResourceManager()
{
	m_text.insert(std::make_pair("sansation", createText("sansation.ttf")));
	m_music.emplace("gameMusic", std::unique_ptr<sf::Music>(createMusic("gameMusic.ogg")));
	m_music.emplace("gameMusic", std::unique_ptr<sf::Music>(createMusic("gameMusic.ogg")));
	m_texture.insert(std::make_pair("screenOpen", createTexture("screenOpen.PNG")));
	m_texture.insert(std::make_pair("background", createTexture("background.PNG")));
	m_texture.insert(std::make_pair("ENEMYSPACE", createTexture("ENEMYSPACE.PNG")));
	m_texture.insert(std::make_pair("PLAYERSPACE", createTexture("PLAYERSPACE.PNG")));
	m_texture.insert(std::make_pair("INRUN", createTexture("INRUN.PNG")));
	m_texture.insert(std::make_pair("player", createTexture("player.PNG")));
	m_texture.insert(std::make_pair("immuneGift", createTexture("immuneGift.PNG")));
	m_texture.insert(std::make_pair("eatEnemyGift", createTexture("eatEnemyGift.PNG")));
	m_texture.insert(std::make_pair("enemy", createTexture("enemy.PNG")));
	m_texture.insert(std::make_pair("gameOver", createTexture("gameOver.PNG")));
}
ResourceManager& ResourceManager::instance()
{
	static ResourceManager instance;
	return instance;
}

const std::unique_ptr<sf::Music>& ResourceManager::getMusic(std::string sound)
{
	return m_music.at(sound);
}

const sf::Texture& ResourceManager::getPicture(std::string picture)
{
	return m_texture.at(picture);
}

const sf::Font& ResourceManager::getText(std::string font)
{
	return m_text.at(font);
}


ResourceManager::ResourceManager(const ResourceManager& other)
{}


sf::Font ResourceManager::createText(const std::string& font)
{
	sf::Font text;
	text.loadFromFile(font);
	return text;
}
std::unique_ptr<sf::Music> ResourceManager::createMusic(const std::string& sound)
{
	auto music = std::make_unique<sf::Music>();
	music->openFromFile(sound);
	return music;
}
sf::Texture ResourceManager::createTexture(const std::string& picture)
{
	sf::Texture texture;
	texture.loadFromFile(picture);
	return texture;
}

