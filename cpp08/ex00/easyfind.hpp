#ifndef CPP_EASYFIND_HPP
#define CPP_EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <iostream>
#include <exception>

template< typename T>
typename T::iterator easyfind(T &in, int i)
{
	typename T::iterator	it;
	it = find(in.begin(), in.end(), i);
	if (it == in.end())
	{
		throw (std::exception());
	}
	return (it);
}

#endif //CPP_EASYFIND_HPP
