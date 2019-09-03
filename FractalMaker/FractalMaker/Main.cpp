
#include <iostream>
#include <fstream>

#include "Shape.h"
#include "GridShape.h"

const size_t numIterations = 18;

int main()
{
	//Shape test0({left, up});

	//GridShape noBorderTest(test0);
	//GridShape borderTest(test0, 3);

	//std::cout << noBorderTest << std::endl << borderTest << std::endl;

	//Shape test1({ left, left });
	//Shape test2({down, down});
	//Shape test3 = test1 + test2;

	//std::cout << GridShape(test3, 2) << std::endl;

	//test3.RotateRight90();
	//std::cout << GridShape(test3, 2) << std::endl;

	//Shape test4({ right, right, down, down, left, left, left, left, up, up, up, up, right, right, right, right });
	//std::cout << GridShape(test4) << std::endl << GridShape(test4, 2) << std::endl;
	//test4.RotateRight90();
	//std::cout << GridShape(test4) << std::endl << GridShape(test4, 2) << std::endl;

	Shape s1({ right, right, right });
	Shape s2 = s1;

	for (size_t i = 0; i < numIterations; ++i)
	{
		s2 = s1;
		s2.RotateRight90();
		s1 = s1 + s2;
	}

	std::ofstream output("output.txt");
	GridShape gs1(s1);
	output << gs1;
	gs1.WriteToPPM("output.ppm");
}
