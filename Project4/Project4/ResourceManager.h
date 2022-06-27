#pragma once
#include <map>
#include <string>
#include <memory>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
class ResourceManager
{
public:
	~ResourceManager() {};
	static ResourceManager& instance();
	const sf::Font& getText(std::string font);
	const sf::Texture& getPicture(std::string picture);
	const std::unique_ptr<sf::Music>& getMusic(std::string sound);
private:
	ResourceManager();
	std::map<std::string, sf::Font> m_text;
	ResourceManager(const ResourceManager& rec);
	std::map<std::string, sf::Texture> m_texture;
	sf::Font createText(const std::string& font);
	sf::Texture createTexture(const std::string& picture);
	std::map<std::string, std::unique_ptr<sf::Music>> m_music;
	std::unique_ptr<sf::Music> createMusic(const std::string& sound);
};

