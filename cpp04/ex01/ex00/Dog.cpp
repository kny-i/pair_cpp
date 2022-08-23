//
// Created by 小平波琉 on 2022/08/14.
//

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cerr << "(Dog default constructor called)" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Animal &rhs)
{
	std::cerr << "(Dog copy constructor called)" << std::endl;
	*this = rhs;
}

Dog::~Dog()
{
	delete this->brain;
	std::cerr << "(Dog destructor called)" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		Animal::type = rhs.Animal::type;
	}
	this->type = rhs.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << CYAN << "BOW WOW!" << STOP << std::endl;
}

void Dog::setIdea(size_t index, const std::string &idea)
{
	this->brain->setIdea(index, idea);
}

const std::string *Dog::getIdea(size_t index)
{
	return (this->brain->getIdea(index));
}
