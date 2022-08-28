#include "Intern.hpp"

Intern::Intern()
{
	std::cerr << "(Intern constructor called)" << std::endl;
}

Intern::~Intern()
{
	std::cerr << "(Intern destructor called)" << std::endl;
}

Intern::Intern(const Intern &rhs)
{
	std::cerr << "(Copy constructor called)" << std::endl;
	*this = rhs;
}

Intern &Intern::operator=(const Intern &rhs) {
	if (this != &rhs) {
		(void)rhs;
	}
	return *this;
}

Form *Intern::newPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::newRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::newShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(std::string name, std::string target)
{
	size_t index =
			(name == "shrubbery creation") * 1+
			(name == "robotomy request") * 2 +
			(name == "presidential pardon") * 3;
	if (index == 0) {
		throw Intern::formException();
	} else {
		std::cout << "Intern creates " << name << "form" << std::endl;
		switch (index) {
			case 1 :
				return new ShrubberyCreationForm(target);
			case 2 :
				return new RobotomyRequestForm(target);
			case 3:
				return new PresidentialPardonForm(target);
		}
	}
	return NULL;
}

const char *Intern::formException::what() const throw()
{
	return "FORM EXCEPTION!!";
}
