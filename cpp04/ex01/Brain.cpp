//
// Created by 小平波琉 on 2022/08/21.
//

#include "Brain.hpp"

Brain::Brain()
{
	std::cerr << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cerr << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &rhs)
{
	std::cerr << "Copy constructor called" << std::endl;
	*this = rhs;
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cerr << "Brain Assignation operator called" << std::endl;
	if (this != &rhs) {
		for (size_t i = 0; i < 100; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

//const std::string	Brain::getIdeas(size_t i) const
//{
//	if (0 <= i && i <= 100)
//		return (this->ideas[i]);
//}


