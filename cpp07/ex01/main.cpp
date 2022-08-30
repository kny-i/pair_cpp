//
// Created by 小平波琉 on 2022/08/04.
//
#include "iter.hpp"

int main()
{
	{
		std::cout << "[INT CASE]" << std::endl;
		int array[] = {1, 2, 3};
		::iter(array, sizeof(array) / sizeof(array[0]), print);
	}

	{
		std::cout << std::endl << "[DOUBLE CASE]" << std::endl;
		double array[] = {1.23, 4.56, 7.89};
		::iter(array, sizeof(array) / sizeof(array[0]), print);
	}

	{
		std::cout << std::endl << "[DOUBLE CASE]" << std::endl;
		char array[] =
				{'4',
				 '2',
				 'T',
				 'o',
				 'k',
				 'y',
				 'o',
				 '!', '\0'};
		::iter(array, sizeof(array) / sizeof(array[0]), print);
	}
	{
		std::cout << std::endl << "[STRING CASE]" << std::endl;
		std::string array[] = {"NOP", "SATAHARU",  "BUNJIRO"};
		::iter(array, sizeof(array) / sizeof(array[0]), print);
	}
}
