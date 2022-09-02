
#ifndef CPP_MUTANTSTACK_HPP
#define CPP_MUTANTSTACK_HPP


#include <iostream>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T> stack;
	typedef typename stack::container_type container;
	typedef typename container::iterator iterator;

	MutantStack() : stack()
	{
		std::cout << "Default Constructor called" << std::endl;
	}
	MutantStack(const stack &rhs) : stack(rhs)
	{
		std::cout << "Copy Constructor called" << std::endl;
	}
	~MutantStack()
	{
		std::cout << "Destructor called" << std::endl;
	}
	stack &operator=(const stack &rhs)
	{
		if (*this != rhs)
			*this = rhs;
		return (*this);
	}

	iterator begin()
	{
		return (stack::c.begin());
	}

	iterator end()
	{
		return (stack::c.end());
	}
};
#endif //CPP_MUTANTSTACK_HPP
