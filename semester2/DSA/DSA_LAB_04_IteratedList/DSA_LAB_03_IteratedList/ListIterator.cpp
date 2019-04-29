#include "ListIterator.h"
#include <exception>

ListIterator::ListIterator(const IteratedList & c):l {c}, current_index{c.head}
{
}

//Theta(1)
void ListIterator::first()
{
	this->current_index = this->l.head;
}

//Theta(1)
void ListIterator::next()
{
	if (this->current_index == -1)
		throw std::exception("Invalid iterator!");
	this->current_index = this->l.next[this->current_index];
}

//Theta(1)
bool ListIterator::valid() const
{
	return this->current_index != -1;
}

//Theta(1)
TElem ListIterator::getCurrent() const
{
	if (this->current_index == -1)
		throw std::exception("Invalid Iterator!");
	TElem elem = this->l.elems[this->current_index];
	return elem;
}
