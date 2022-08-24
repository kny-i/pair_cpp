//
// Created by 小平波琉 on 2022/08/14.
//

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain_(new Brain())
{
	std::cerr << "(Dog default constructor called)" << std::endl;
}

Dog::Dog(const Animal &rhs) : Animal("Dog") , brain_(new Brain())
{
	std::cerr << "(Dog copy constructor called)" << std::endl;
	*this = rhs;
}

Dog::~Dog()
{
	std::cerr << "(Dog destructor called)" << std::endl;
	delete this->brain_;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		Animal::type = rhs.Animal::type;
		*this->brain_ = *rhs.brain_;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << CYAN << "BOW WOW!" << STOP << std::endl;
}

void Dog::setIdea(size_t index, const std::string &idea)
{
	this->brain_->setIdea(index, idea);
}

const std::string *Dog::getIdea(size_t index)
{
	return (this->brain_->getIdea(index));
}
