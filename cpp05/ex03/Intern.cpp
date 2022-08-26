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

	}
	return *this;
}

Form *Intern::makeForm(std::string name, std::string target)
{
	std::cout << "Intern creates " << formName << " form" << std::endl;
	return NULL;
}
