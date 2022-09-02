#include "easyfind.hpp"
#include <list>
#include <vector>

int	main()
{
	//int version
	std::list<int> ilist;

	ilist.push_back(1);
	ilist.push_back(2);
	ilist.push_back(3);

	std::list<int>::const_iterator iIt;

	try {
		iIt = ::easyfind(ilist, 2);
		std::cout << *iIt << " is in the list" << std::endl;
	}catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		iIt = ::easyfind(ilist, 4);
		std::cout << *iIt << "is in the list" << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::vector<int>::const_iterator vit;
	try {
		vit = ::easyfind(v, 2);
		std::cout << *vit << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		vit = ::easyfind(v, 100);
		std::cout << *vit << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
