//
// Created by 小平波琉 on 2022/08/14.
//

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cerr << "(Cat default constructor called)" << std::endl;
}

Cat::Cat(const Animal &rhs)
{
	std::cerr << "(Cat copy constructor called)" << std::endl;
	*this = rhs;
}

Cat::~Cat()
{
	std::cerr << "(Cat destructor called)" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		Animal::type = rhs.Animal::type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << BLUE << "MEOW!" << STOP << std::endl;
}
