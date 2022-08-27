#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: Form("Default PresidentialPardonForm", 25, 5)
{
	std::cerr << "(PresidentialPardonForm constructor called)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : Form(rhs)
{
	std::cerr << "(PresidentialPardonForm copy constructor called)" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs) {
		Form::operator=(rhs);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cerr << "PresidentialPardonForm destructor called" << std::endl;
}

/* Member funcs */
//void	PresidentialPardonForm::execute(const Bureaucrat& b)
//{
//	this->throwExecuteException(b);
//	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
//}
