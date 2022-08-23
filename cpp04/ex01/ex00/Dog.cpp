//
// Created by 小平波琉 on 2022/08/14.
//

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cerr << "(Dog default constructor called)" << std::endl;
}

Dog::Dog(const Animal &rhs)
{
	std::cerr << "(Dog copy constructor called)" << std::endl;
	*this = rhs;
}

Dog::~Dog()
{
	std::cerr << "(Dog destructor called)" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		Animal::type = rhs.Animal::type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << CYAN << "BOW WOW!" << STOP << std::endl;
}
