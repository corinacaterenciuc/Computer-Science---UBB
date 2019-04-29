#pragma once

#include<vector>

#include<utility>




using namespace std;


typedef int TKey;

typedef int TValue;

typedef bool(*Condition)(TValue);



typedef std::pair<TKey, TValue> TElem;

//class SLLNode
//{
//	TElem value;
//	SLLNode* next;
//
//	SLLNode(TElem e, SLLNode* n);
//};

struct SLLNode
{
	TElem value;
	SLLNode* next;
	
};

class MultiMapIterator;

class MultiMap

{



private:

	/* representation of the MultiMap */
	

	SLLNode* head;

	friend class MultiMapIterator;



public:

	//constructor

	MultiMap();



	//adds a key value pair to the multimap

	void add(TKey c, TValue v);



	//removes a key value pair from the multimap

	//returns true if the pair was removed (if it was in the multimap) and false otherwise

	bool remove(TKey c, TValue v);



	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty

	vector<TValue> search(TKey c) const;



	//returns the number of pairs from the multimap

	int size() const;



	//checks whether the multimap is empty

	bool isEmpty() const;



	//returns an iterator for the multimap

	MultiMapIterator iterator() const;

	//keeps in the MultiMap only those pairs whose value respect the given condition

	void filter(Condition cond);

	//



	//descturctor

	~MultiMap();





};


