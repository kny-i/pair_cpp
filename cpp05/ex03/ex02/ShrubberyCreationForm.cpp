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

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	checkException(executor);
	std::string file(this->getTarget() + "_shrubbery");
	std::ofstream ofs(file);
	if (ofs.fail()) {
		throw "open filestream error";
	} else {
		ofs << ".\n"
			   "├── Default ShrubberyCreationForm target_shrubbery\n"
			   "├── Makefile\n"
			   "├── PresidentialPardonForm.cpp\n"
			   "├── PresidentialPardonForm.hpp\n"
			   "├── RobotomyRequestForm.cpp\n"
			   "├── RobotomyRequestForm.hpp\n"
			   "├── ShrubberyCreationForm.cpp\n"
			   "├── ShrubberyCreationForm.hpp\n"
			   "├── ex01\n"
			   "├── Form.cpp\n"
			   "│── Form.hpp\n"
			   "│── Makefile\n"
			   "└── ex00\n"
			   "├── Bureaucrat.cpp\n"
			   "├── Bureaucrat.hpp\n"
			   "└── Makefile\n"
			   "└── main.cpp\n"
			   << std::endl;
	}
}

