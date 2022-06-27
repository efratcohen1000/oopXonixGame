#pragma once
#include <map>
#include "Objects.h"
#include <iostream>
#include <functional>
#include "MoveObjects.h"
class MoveObjects:
	public Objects
{
public:
	virtual ~MoveObjects() {};
	MoveObjects(sf::Vector2f pos);
	//std::unique_ptr<MoveObjects> createObject(const std::string& name);
	//void writeObject(const std::string& name, std::function< std::unique_ptr<MoveObjects>()>f);
protected:
	//std::map<std::string, std::function< std::unique_ptr<MoveObjects>()>> m_map;
};