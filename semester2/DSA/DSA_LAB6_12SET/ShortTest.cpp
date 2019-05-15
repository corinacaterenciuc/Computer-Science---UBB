#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"

void test_union()
{
	Set s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0);
	assert(s.add(0) == true);
	assert(s.add(1) == true);
	assert(s.add(2) == true);
	assert(s.add(3) == true);
	assert(s.add(1) == false);
	assert(s.add(4) == true);
	assert(s.add(-1) == true);
	assert(s.size() == 6);

	Set s_this;
	assert(s_this.add(3) == true);
	assert(s_this.add(4) == true);
	assert(s_this.add(5) == true);
	assert(s_this.add(6) == true);
	assert(s_this.add(7) == true);
	assert(s_this.size() == 5);

	//s_this has elements 3->7 and s has elements -1->4
	//their union in s_this should be: -1->7 => 9 elements

	s_this._union(s);
	assert(s_this.size() == 9);


}

void testAll() {
	Set s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0);
	assert(s.add(5) == true);
	assert(s.add(1) == true);
	assert(s.add(10) == true);
	assert(s.add(7) == true);
	assert(s.add(1) == false);
	assert(s.add(10) == false);
	assert(s.add(-3) == true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
	assert(s.remove(1) == true);
	assert(s.remove(6) == false);
	assert(s.size() == 4);


	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 19);



}

