#include "collide.h"
//���� �� ����� ������� ��� 2 ���������� ������
bool collideObjects(Objects& a, Objects& b)
{
	if (a.getObject().getGlobalBounds().intersects(b.getObject().getGlobalBounds()))
		return true;
	return false;
}