#include "Bureaucrat.hpp"


void Bureaucrat::gradeUp()
{
	if (grade_ <= 1) {
		throw GradeTooHighException();
	} else {
		grade_ -= 1;
	}
}

void Bureaucrat::gradeDown()
{
	if (grade_ >= 150) {
		throw GradeTooLowException();
	} else {
		grade_ += 1;
	}
}

/* canonical form & accessor */
Bureaucrat::Bureaucrat() : name_("NomalBureaucrat"), grade_(42)
{
	std::cerr << "(Bureaucrat constructor called)" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade) : name_(name), grade_(grade)
{
	std::cerr << "(Bureaucrat constructor called)" << std::endl;
	if (grade_ < 1) {
		throw GradeTooHighException();
	}
	if (grade_ > 150) {
		throw GradeTooHighException();
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cerr << "(Bureaucrat destructor called)" << std::endl;
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
	if (grade_ < 1) {
		throw GradeTooHighException();
	} else if (grade_ > 150) {
		throw GradeTooHighException();
	}
	grade_ = grade;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
