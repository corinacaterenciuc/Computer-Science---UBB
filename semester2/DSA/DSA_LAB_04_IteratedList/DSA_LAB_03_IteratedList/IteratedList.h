#pragma once



typedef int TElem;

class ListIterator;

class IteratedList {

private:



	/*Representation of the IteratedList*/
	int cap;
	TElem * elems;
	TElem* next;
	int head;
	int firstEmpty;
	int size_elems;


	void resize();


	friend class ListIterator;


public:



	// constructor

	IteratedList();

	IteratedList(const IteratedList &l);

	IteratedList& operator=(const IteratedList& l);




	// returns the number of elements from the list

	int size() const;



	// verifies if the list is empty

	bool isEmpty() const;



	// returns the first position from the list

	ListIterator first() const;



	// returns the element from the given position

	//throws an exception if the position is not valid

	TElem getElement(ListIterator pos) const;



	// changes the element from the current position to the given one.

	//returns the old value from the position

	//throws exception if the position is not valid

	TElem setElement(ListIterator pos, TElem e);



	// adds a new element to the end of the list

	void addToEnd(TElem e);



	// adds a new element to a given position

	//after addition, pos points to the newly added element

	//throws an exception if pos is not valid

	void addToPosition(ListIterator pos, TElem e);



	// removes the element from position pos

	//returns the removed element

	//after removal pos is positioned on the next element (the one after the removed one) or it is invalid if the last element was removed

	//arunca exceptia daca poz nu e valid

	TElem remove(ListIterator pos);



	// searches for the first occurrance of an element 

	//returns an iterator that points to the element, if it appear in the list, or an invalid iterator if the element is not in the list

	ListIterator search(TElem e) const;

	//reverses all elements between two positions, start and end
	//throws exception if start or end is not valid

	void reverseBetween(ListIterator start, ListIterator end);



	//destructor



	~IteratedList();

};
