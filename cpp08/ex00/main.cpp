#include "easyfind.hpp"
#include <list>

int	main()
{
	std::list<int> ilist;

	ilist.push_back(1);
	ilist.push_back(2);
	ilist.push_back(3);

	std::list<int>::const_iterator it;

	try {
		it = ::easyfind(ilist, 2);
		std::cout << *it << " is in the list" << std::endl;
	}catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		it = ::easyfind(ilist, 4);
		std::cout << *it << "is in the list" << std::endl;

	}catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
