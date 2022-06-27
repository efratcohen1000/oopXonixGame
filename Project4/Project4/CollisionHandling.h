#pragma once
#include <iostream>
#include "Objects.h"
class Controller;
struct UnknownCollision
{
	UnknownCollision(Objects& a, Objects& b) : first(a), second(b)
	{
		std::cout << "Unkown collision of " << typeid(a).name() << " and "
			<< typeid(b).name() << std::endl;
	}
	Objects& first;
	Objects& second;
};
void processCollision(Objects& Obj1, Objects& obj2);