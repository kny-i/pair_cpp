//
// Created by 小平波琉 on 2022/08/14.
//

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cerr << "(Cat default constructor called)" << std::endl;
	this->brain_ = new Brain;
}

Cat::Cat(const Animal &rhs)
{
	std::cerr << "(Cat copy constructor called)" << std::endl;
	*this = rhs;
}

Cat::~Cat()
{
	std::cerr << "(Cat destructor called)" << std::endl;
	delete this->brain_;
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

void Cat::setIdea(size_t index, const std::string &idea)
{
	this->brain_->setIdea(index, idea);
}

const std::string *Cat::getIdea(size_t index)
{
	return (this->brain_->getIdea(index));
}
