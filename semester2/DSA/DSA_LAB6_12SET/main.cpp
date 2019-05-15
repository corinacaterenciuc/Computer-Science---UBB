#include "Set.h"
#include "ShortTest.h"
#include "ExtendedTest.h"

#include <iostream>

int main()
{
	testAll();
	
	test_union();
	std::cout << "Union performed successfully!\n";

	testAllExtended();


	std::cout << "GOOD JOB!";
	return 0;
}