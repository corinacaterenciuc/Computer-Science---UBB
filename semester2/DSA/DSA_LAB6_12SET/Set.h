#pragma once

//#include "SetIterator.h"

#include <cmath>
#include <cstdlib>
#include <climits>
#include <stdexcept>

#define CONST_KNUTH 0.618

typedef int TElem;

class Set;

long long h_1(TElem elem, const Set &set);
long long h_2(TElem elem, const Set &set);
long long hash(TElem elem, int tries, const Set &set);

class SetIterator;



class Set {


	friend long long h_1(TElem elem, const Set &set);
	friend long long h_2(TElem elem, const Set &set);
	friend long long hash(TElem elem, int tries, const Set &set);

	friend class SetIterator;


private:

	long long(*h1)(TElem elem, const Set &set) = &h_1;
	long long(*h2)(TElem elem, const Set &set) = &h_2;
	long long(*h)(TElem elem, int tries, const Set &set) = &hash;
	
	int m;
	int prime;
	TElem* elems;
	int size_count;

	void resize_rehash();





public:

	//implicit constructor

	Set();



	//adds an element to the  set

	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 

	//it returns false

	bool add(TElem e);



	//removes an element from the set

	//if the element was removed, it returns true, otherwise false

	bool remove(TElem e);



	//checks if an element is in the  set

	bool search(TElem elem) const;



	//returns the number of elements;

	int size() const;



	//checks if the set is empty

	bool isEmpty() const;



	//returns an iterator for the set

	SetIterator iterator() const;

	//extra operation
	// adds all elements of s into this set
	void _union(const Set& s);



	//destructor

	~Set();



};










