
#include <iostream>

#include "Shape.h"
#include "GridShape.h"

int main()
{
	Shape test({right, down, right, right, down, down, left, left, left, up});

	GridShape noBorderTest(test);
	GridShape borderTest(test, 3);

	std::cout << noBorderTest << std::endl << borderTest;

	getchar();
}
