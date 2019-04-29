#include "MultiMapIterator.h"
#include <exception>

////Theta(1)
MultiMapIterator::MultiMapIterator(const MultiMap& c): mm {c} , current_elem (c.head)
{
	/*this->mm = c;
	this->current_elem = c.head;*/
}

//Theta(1)
void MultiMapIterator::first()
{
	this->current_elem = this->mm.head;
}

//Theta(1)
void MultiMapIterator::next()
{
	if (this->current_elem == NULL)
		throw std::exception("Invalid iterator!");
	this->current_elem = this->current_elem->next;
}

//Theta(1)
bool MultiMapIterator::valid() const
{
	if (this->current_elem == NULL)
		return false;
	return true;
}

//Theta(1)
TElem MultiMapIterator::getCurrent() const
{
	TElem elem = this->current_elem->value;
	if (this->current_elem == NULL)
	{
		throw std::exception("Invalid iterator");
	}
	return elem;
}


