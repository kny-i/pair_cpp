//
// Created by 小平波琉 on 2022/08/21.
//

#include "Brain.hpp"

Brain::Brain()
{
	std::cerr << "(Brain default constructor called)" << std::endl;
}

Brain::~Brain()
{
	std::cerr << "(Brain destructor called)" << std::endl;
}

Brain::Brain(const Brain &rhs)
{
	std::cerr << "(Copy constructor called)" << std::endl;
	*this = rhs;
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cerr << "(Brain Assignation operator called)" << std::endl;
	if (this != &rhs) {
		for (size_t i = 0; i < 100; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

void	Brain::setIdea(size_t index, const std::string &str)
{
	if (index < 100) {
		this->ideas[index] = str;
	} else {
		std::cerr << "index should be between 0 to 99" <<  std::endl;
	}
}

const std::string *Brain::getIdea(size_t index)
{
	if (index < 100) {
		return &this->ideas[index];
	} else {
		std::cerr << "index should be between 0 to 99" << std::endl;
		return NULL;
	}
}
