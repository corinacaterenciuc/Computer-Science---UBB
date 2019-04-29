#include "Comparators.h"



bool AscendingByLikes::compare(Tutorial t1, Tutorial t2)
{
	if (t1.get_likes() <= t2.get_likes())
		return true;
	return false;
}

bool DescendingByTitle::compare(Tutorial t1, Tutorial t2)
{
	if (t1.get_title() >= t2.get_title())
		return true;
	return false;
}
