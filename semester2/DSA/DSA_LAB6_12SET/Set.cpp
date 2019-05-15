#include "Set.h"
#include "SetIterator.h"


bool is_prime(int n)
{
	if (n < 2)
		return false;
	if (n % 2 == 0 || n == 3)
		return false;

	for (int d = 3; d*d <= n; d++)
	{
		if (n % d == 0)
			return false;
	}

	return true;
}


//Theta(m)
void Set::resize_rehash()
{

	TElem* new_elems, elem;
	int pos, old_m = this->m;

	this->prime = this->m;

	this->m *= 2;
	while (!is_prime(this->m))
	{
		this->m += 1;
	}

	new_elems = new TElem[this->m];
	for (int i = 0; i < this->m; i++)
	{
		new_elems[i] = INT_MIN;
	}

	for (int i = 0; i < old_m; i++)
	{
		if (this->elems[i] != INT_MIN)
		{
			elem = this->elems[i];
			for (int tries = 0; tries < this->m; tries++)
			{
				pos = this->h(elem, tries, *this);
				if (new_elems[pos] == INT_MIN)
				{
					new_elems[pos] = elem;
					break;
				}
			}
		}
	}

	delete[] this->elems;
	this->elems = new_elems;

}

//Theta(1)
Set::Set()
{

	this->size_count = 0;
	this->prime = 2;
	this->m = 3;
	this->elems = new TElem[3];
	this->elems[0] = this->elems[1] = this->elems[2] = INT_MIN;

}

//O(m)
bool Set::add(TElem e)
{
	int pos, tries;

	if (this->size_count == this->m)
		this->resize_rehash();

	for (tries = 0; tries < this->m; tries++)
	{
		pos = this->h(e, tries, *this);

		if (this->elems[pos] == INT_MIN)
		{
			this->elems[pos] = e;
			this->size_count++;
			return true;
		}

		if (this->elems[pos] == e)
			return false;
	}

	if (tries == this->m)
		throw std::exception("The hash function does not generate a permutation! \n");

	return false;
}

//O(m)
bool Set::remove(TElem e)
{
	int pos;

	for (int tries = this->m - 1; tries >= 0; tries--)
	{
		pos = this->h(e, tries, *this);

		if (this->elems[pos] == e)
		{
			this->elems[pos] = INT_MIN;
			this->size_count--;
			return true;
		}
	}

	return false;
}

//O(m)
bool Set::search(TElem elem) const
{
	int pos;

	for (int tries = 0; tries < this->m; tries++)
	{
		pos = this->h(elem, tries, *this);

		if (this->elems[pos] == INT_MIN)
		{
			return false;
		}

		if (this->elems[pos] == elem)
		{
			return true;
		}
	}

	return false;
}

int Set::size() const
{
	return this->size_count;
}

bool Set::isEmpty() const
{
	return this->size_count == 0;
}

//O(m)
SetIterator Set::iterator() const
{
	//SetIterator it{ *this };
	return SetIterator(*this);
}

//O(m)
void Set::_union(const Set & s)
{
	SetIterator it_s = s.iterator();
	it_s.first();
	while (it_s.valid())
	{
		this->add(it_s.getCurrent());
		it_s.next();
	}

}

//Theta(1)
Set::~Set()
{
	delete[] this->elems;
}

















long long h_1(TElem elem, const Set & set)
{
	//division method;

	if (elem < 0)
		elem = abs(elem);
	return elem % set.m;
}

long long h_2(TElem elem, const Set & set)
{
	if (elem < 0)
		elem = abs(elem);
	return set.prime - (elem % set.prime);
}

long long hash(TElem elem, int tries, const Set & set)
{
	//double hashing;

	int h1_result, h2_result;

	h1_result = set.h1(elem, set);
	h2_result = set.h2(elem, set);

	return (h1_result + h2_result * tries) % set.m;
}
