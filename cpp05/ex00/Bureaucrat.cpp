//
// Created by 小平波琉 on 2022/08/04.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cerr << "(Bureaucrat constructor called)" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cerr << "(Bureaucrat Destructor called)" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
{
	*this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs) {
		grade_ = rhs.getGrade();
	}
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return name_;
}

size_t Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::setGrade(size_t grade) {
	grade_ = grade;
}
