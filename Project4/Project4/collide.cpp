#include "collide.h"
//בודק אם הייתה התנגשות בין 2 האובייקטים שנשלחו
bool collideObjects(Objects& a, Objects& b)
{
	if (a.getObject().getGlobalBounds().intersects(b.getObject().getGlobalBounds()))
		return true;
	return false;
}