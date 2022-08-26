#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{
	std::cerr << "(ShrubberyCreationForm default constructor called)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : Form(rhs)
{
	std::cerr << "(ShrubberyCreationForm copy constructor called)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
	(void)target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs) {
		Form::operator=(rhs);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cerr << "(ShrubberyCreationForm destructor called)" << std::endl;
}

