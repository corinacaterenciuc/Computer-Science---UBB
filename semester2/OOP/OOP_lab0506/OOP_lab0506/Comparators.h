#pragma once
#include "Tutorial.h"
#include "Comparator.h"

class AscendingByLikes : public Comparator<Tutorial>
{
public:

	bool compare(Tutorial t1, Tutorial t2);


};

class DescendingByTitle : public Comparator<Tutorial>
{
public:

	bool compare(Tutorial t1, Tutorial t2);
};



