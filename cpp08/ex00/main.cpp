#include "easyfind.hpp"
#include <list>

int	main()
{
	std::list<int> ilist;

	ilist.push_back(1);
	ilist.push_back(2);
	ilist.push_back(3);

	//要素を修正できるイテレータ（iterator）、参照のみが可能なイテレータ（const_iterator）がある
	//begin(), end() で（非const）イテレータを取得、cbegin(), cend() で const イテレータを取得出来る
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
