#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
		: Form("Default ShrubberyCreationForm",
			   145,
			   137,
			   "Default ShrubberyCreationForm target")
{
	std::cerr << "(ShrubberyCreationForm default constructor called)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: Form("Default ShrubberyCreationForm",
			   145,
			   137,
			   target)
{
	std::cerr << "(ShrubberyCreationForm default constructor called)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : Form(rhs)
{
	std::cerr << "(ShrubberyCreationForm copy constructor called)" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs) {
		Form::operator=(rhs);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cerr << "(ShrubberyCreationForm destructor called)" << std::endl;
}

