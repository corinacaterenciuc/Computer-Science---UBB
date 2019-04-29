#include "MultiMap.h"
#include "MultiMapIterator.h"


MultiMap::MultiMap(): head{NULL}
{
}

//Theta(1)
void MultiMap::add(TKey c, TValue v)
{
	std::pair <TKey, TValue> elem;
	elem = std::make_pair(c, v);
	SLLNode* new_node = new SLLNode[1];
	new_node->value = elem;
	new_node->next = this->head;
	this->head = new_node;
	

}

//O(n)
bool MultiMap::remove(TKey c, TValue v)
{
	std::pair <TKey, TValue> elem = std::make_pair(c, v);
	SLLNode* current = this->head;
	SLLNode* prev = NULL;

	while (current != NULL && current->value != elem)
	{
		prev = current;
		current = current->next;
	}
	if (current != NULL && prev == NULL)
	{
		this->head = this->head->next;
		delete current;
		return true;
	}
	else if (current != NULL)
	{
		prev->next = current->next;
		current->next = NULL;
		delete current;
		return true;
	}

	delete current; 


	return false;
}

//O(n)
vector<TValue> MultiMap::search(TKey c) const
{
	vector<TValue> v{};
	
	SLLNode* current = this->head;
	while (current != NULL)
	{
		if (current->value.first == c)
		{
			v.push_back(current->value.second);
		}
		current = current->next;
	}
	   
	return v;
}

//O(n)
int MultiMap::size() const
{
	int count = 0;
	SLLNode* current = this->head;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

//Theta(1)
bool MultiMap::isEmpty() const
{
	return (this->head == NULL);
}

//Theta(1)
MultiMapIterator MultiMap::iterator() const
{
	MultiMapIterator m_it { *this };
	return m_it;
}

void MultiMap::filter(Condition cond)
{
	/*SLLNode* current = this->head;
	while (current != NULL)
	{
		if (cond(current->value.second) == false)
		{
			this->remove(current->value.first, current->value.second);
		}
		current = this->head->next;
	}*/

	SLLNode* new_current = this->head;
	SLLNode* current = this->head;
	SLLNode* prev = NULL;

	while (current != NULL )
	{
		if (cond(current->value.second) == false)
		{
			if (current != NULL && prev == NULL)
			{
				new_current = current;
				this->head = this->head->next;
				current = this->head;
				delete new_current;
				
			}
			else if (current != NULL)
			{
				new_current = current;
				prev->next = current->next;
				current = prev->next;

				new_current->next = NULL;

				delete new_current;
				
			}
		}
		else
		{
			prev = current;
			current = current->next;
		}
		
		

	}
}

//O(n)
MultiMap::~MultiMap()
{
	SLLNode* aux = this->head;
	while (aux != NULL)
	{
		this->head = aux->next;
		delete aux;
		aux = this->head;
	}
}

