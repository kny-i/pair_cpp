#include <iostream>
#include "Array.hpp"

/* from PDF */

#define MAX_VAL 100
int main(int, char**)
{
	// --PDF--
	std::cout << "--PDF--" << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;

	std::cout << "_____OTHER TEST______" << std::endl;
	Array<int> test(0); // empty array
	Array<int> test_100(100); // specific size of array

	printArray(test);
	printArray(test_100);

//	Array<std::string> stringArray;
//	stringArray[0] = "Hello";
//	stringArray[1] = "42";
//	stringArray[2] = "tokyo";
//	for (size_t i = 0; stringArray[i]; i++) {
//		std::cout << stringArray[i] << std::endl;
//	}
}
