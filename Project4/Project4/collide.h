#pragma once
#include <algorithm>
#include"Objects.h"

template <typename FwdIt, typename Fn>
void for_each_pair(FwdIt begin, FwdIt end, Fn func)
{
	for (; begin != end; ++begin)
		for (FwdIt second = begin + 1; second != end; ++second)
			func(*begin, *second);   //הפונקציה
}

bool collideObjects(Objects& a, Objects& b);
