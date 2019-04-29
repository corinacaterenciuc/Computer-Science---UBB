#include "ShortTest.h"

#include <assert.h>
#include <exception>


#include "IteratedList.h"
#include "ListIterator.h"



using namespace std;

void test_reverseBetween() {

	IteratedList list = IteratedList();
	int values[] = { 1,2,3,4 };
	int reversed[] = { 4,3,2,1 };
	list.addToEnd(1);
	list.addToEnd(2);
	list.addToEnd(3);
	list.addToEnd(4);
	
	ListIterator check_pos = list.search(1);
	for (int i = 0; i < 4; i++)
	{
		assert(check_pos.getCurrent() == values[i]);
		check_pos.next();
	}


	ListIterator start = list.search(1);
	ListIterator end = list.search(4);

	list.reverseBetween(start, end);

	ListIterator check_pos_rev = list.search(4);
	for (int i = 0; i < 4; i++)
	{
		assert(check_pos_rev.getCurrent() == reversed[i]);
		check_pos_rev.next();
	}
}

void testAll() {

	test_reverseBetween();

	IteratedList list = IteratedList();
	assert(list.size() == 0);
	assert(list.isEmpty());

	list.addToEnd(1);
	assert(list.size() == 1);
	assert(!list.isEmpty());

	ListIterator it = list.search(1);
	assert(it.valid());
	assert(it.getCurrent() == 1);
	it.next();
	assert(!it.valid());
	it.first();
	assert(it.valid());
	assert(it.getCurrent() == 1);

	assert(list.remove(it) == 1);
	assert(list.size() == 0);
	assert(list.isEmpty());


}



