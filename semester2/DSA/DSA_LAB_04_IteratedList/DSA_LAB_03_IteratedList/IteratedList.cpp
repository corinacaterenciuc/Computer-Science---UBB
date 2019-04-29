#include "IteratedList.h"
#include "ListIterator.h"
#include <exception>

//Theta(n)
void IteratedList::resize()
{
	this->cap *= 2;
	TElem* new_elems = new TElem[this->cap];
	TElem* new_next = new TElem[this->cap];
	for (int i = 1; i < this->size_elems+1; i++)
	{
		new_elems[i] = this->elems[i];
		new_next[i] = this->next[i];

	}

	for (int j = this->size_elems + 1; j < this->cap; j++)
	{
		new_next[j] = j + 1;
	}
	new_next[cap] = -1;

	/*delete[] this->elems;
	delete[] this->next;*/

	this->elems = new_elems;
	this->next = new_next;

	
	this->firstEmpty = this->size_elems + 1;
}

//O(n)
IteratedList::IteratedList()
{
	this->cap = 10;
	this->elems = new TElem[this->cap];
	this->next = new TElem[this->cap];
	this->head = -1;
	//this->next[0] = 0;
	for (int i = 1; i < this->cap; i++)
		this->next[i] = i + 1;

	this->next[this->cap] = -1;
	this->firstEmpty = 1;

	this->size_elems = 0;

}

IteratedList::IteratedList(const IteratedList & l)
{
	this->cap = l.cap;
	this->size_elems = l.size_elems;

	this->elems = new TElem[this->cap];
	this->next = new TElem[this->cap];
	this->head = l.head;
	this->firstEmpty = l.firstEmpty;

	for (int i = 1; i <= this->size_elems; i++)
	{
		this->elems[i] = l.elems[i];
		this->next[i] = l.next[i];
	}


}

IteratedList & IteratedList::operator=(const IteratedList & l)
{

	if (this == &l)
		return *this;

	this->cap = l.cap;
	this->size_elems = l.size_elems;
	this->head = l.head;
	this->firstEmpty = l.firstEmpty;

	/*delete[] this->elems;
	delete[] this->next;*/

	this->elems = new TElem[this->cap];
	this->next = new TElem[this->cap];

	int i = 1;
	for (; i <= this->cap; i++)
	{
		this->elems[i] = l.elems[i];
		this->next[i] = l.next[i];
	}

	return *this;

	// TODO: insert return statement here
}

//theta (1)
int IteratedList::size() const
{
	return this->size_elems;
}

//Theta(1)
bool IteratedList::isEmpty() const
{
	return (this->size_elems == 0 && this->head == -1);
}

//Theta(1)
ListIterator IteratedList::first() const
{
	ListIterator it{*this};
	return it;
}

//Theta(1)
TElem IteratedList::getElement(ListIterator pos) const
{

	return pos.getCurrent();
}

//Theta(1)
TElem IteratedList::setElement(ListIterator pos, TElem e)
{
	TElem old = pos.getCurrent();
	this->elems[pos.current_index] = e;
	return old;
}

//O(n)
void IteratedList::addToEnd(TElem e)
{
	if (this->firstEmpty == -1)
		this->resize();

	this->elems[this->firstEmpty] = e;
	int old_empty = this->firstEmpty;
	this->firstEmpty = this->next[this->firstEmpty];
	this->next[old_empty] = -1;

	if (this->head == -1)
	{
		this->head = old_empty;
	}
	else
	{
		int current = this->head;
		while (this->next[current] != -1)
			current = this->next[current];
		this->next[current] = old_empty;
	}

	this->size_elems += 1;

	
	
}


//O(n)
void IteratedList::addToPosition(ListIterator pos, TElem e)
{
	if (!pos.valid())
		throw std::exception("invalid position!");

	if (this->firstEmpty == -1)
		this->resize();

	if (pos.current_index == this->head)
	{
		int new_pos = this->firstEmpty;
		this->elems[new_pos] = e;
		this->firstEmpty = this->next[this->firstEmpty];
		this->next[new_pos] = this->head;
		this->head = new_pos;
	}
	else
	{
		int current_node = this->next[this->head];
		int prev_node = this->head;
		while (current_node != -1 && this->next[prev_node] != pos.current_index)
		{
			prev_node = current_node;
			current_node = this->next[current_node];

		}
		if (current_node != -1)
		{
			int new_next_pos = this->firstEmpty;
			this->firstEmpty = this->next[this->firstEmpty];

			this->elems[new_next_pos] = this->elems[current_node];
			this->elems[current_node] = e;
			this->next[new_next_pos] = this->next[current_node];
			this->next[current_node] = new_next_pos;

			this->size_elems += 1;
		}
		else
			throw std::exception("invalid position!");
	}


}

//O(n)
TElem IteratedList::remove(ListIterator pos)
{
	if (!pos.valid())
		throw std::exception("invalid position!");
	TElem old_elem;
	int current_node = this->head;
	int prev_node = -1;

	while (current_node != -1 && this->elems[current_node] != pos.getCurrent())
	{
		prev_node = current_node;
		current_node = this->next[current_node];
	}

	if (current_node != -1)
	{
		if (current_node == this->head)
		{
			old_elem = this->elems[this->head];
			this->head = this->next[this->head];
			this->size_elems -= 1;
		}
			
		else
		{
			old_elem = this->elems[current_node];
			this->next[prev_node] = this->next[current_node];
			this->size_elems -= 1;
		}
			

		this->next[current_node] = this->firstEmpty;
		this->firstEmpty = current_node;

	}
	else
	{
		throw std::exception("the element does not exist!");
	}



	return old_elem;
}

//O(n)
ListIterator IteratedList::search(TElem e) const
{
	ListIterator it{ *this };
	it.first();
	while (it.valid() && it.getCurrent() != e)
		it.next();
	return it;
}

//Theta(n)
void IteratedList::reverseBetween(ListIterator start, ListIterator end)
{

	if ((!start.valid() || !end.valid()) )
		throw std::exception("Invalid position!");

	TElem* new_next = new TElem[this->cap];
	int new_head = this->head;
	for (int i = 1; i <= this->cap; i++)
	{
		new_next[i] = this->next[i];
	}

	int prev = -1;
	int here = this->head;
	while (here != start.current_index)
	{
		prev = here;
		here = this->next[here];
	}
	if (prev == -1)
		new_head = end.current_index;
	else
		new_next[prev] = end.current_index;
	prev = here;
	here = this->next[here];
	new_next[prev] = this->next[end.current_index];
	
	while (here != this->next[end.current_index])
	{
		new_next[here] = prev;
		prev = here;
		here = this->next[here];
	}


	//reversed list next!
	//delete[] this->next;

	this->next = new_next;
	this->head = new_head;
		

}

IteratedList::~IteratedList()
{

	/*delete[] this->elems;
	delete[] this->next;*/
		
}
