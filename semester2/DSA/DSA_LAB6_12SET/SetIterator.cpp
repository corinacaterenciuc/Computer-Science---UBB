#include "SetIterator.h"

//O(m)
SetIterator::SetIterator(const Set& _set): set{_set}
{
	this->pos = 0;
	while (this->set.elems[this->pos] == INT_MIN && this->pos < this->set.m)
		this->pos++;

	this->first_pos = pos;
}

//Theta(1)
void SetIterator::first()
{
	this->pos = this->first_pos;
}

//O(m)
void SetIterator::next()
{
	this->pos++;

	while (this->set.elems[this->pos] == INT_MIN && this->pos < this->set.m)
		this->pos++;
}

//Theta(1)
bool SetIterator::valid() const
{
	if (this->pos < this->set.m)
		return true;

	return false;
}



//Theta(1)
TElem SetIterator::getCurrent() const
{
	return this->set.elems[this->pos];
}
