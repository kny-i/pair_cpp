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
Bureaucrat::Bureaucrat() : kName_("NomalBureaucrat"), grade_(42)
{
	std::cerr << "(Bureaucrat constructor called)" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade) : kName_(name), grade_(grade)
{
	std::cerr << "(Bureaucrat constructor called)" << std::endl;
	if (grade_ < 1) {
		throw GradeTooHighException();
	}
	if (grade_ > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cerr << "(Bureaucrat destructor called)" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
{
	std::cerr << "(Bureaucrat copy constructor called)" << std::endl;
	*this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs) {
		grade_ = rhs.getGrade();
	}
	return *this;
}

const std::string &Bureaucrat::getName() const
{
	return kName_;
}

size_t Bureaucrat::getGrade() const
{
	return grade_;
}

void Bureaucrat::setGrade(size_t grade)
{
	if (grade_ < 1) {
		throw GradeTooHighException();
	} else if (grade_ > 150) {
		throw GradeTooLowException();
	}
	grade_ = grade;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GRADE IS TOO HIGH!!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GRADE IS TOO LOW!!";
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getKName() << std::endl;
	} catch (std::exception &e) {
		std::cerr
		<< this->getName()
		<< " couldn’t sign "
		<< form.getKName()
		<<  "because ["
		<< e.what()
		<< "]." << std::endl;
	}
}

void Bureaucrat::executeForm(const Form &form)
{
	try {
		form.execute(*this);
		std::cout
		<< this->getName()
		<< " executed "
		<< form.getKName()
		<< std::endl;
	} catch (std::exception &e) {
		std::cerr << "executeForm failure!!" << std::endl;
	}
}

