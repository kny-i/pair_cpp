

#include "PresidentialPardonForm.hpp"

/* Caronical */
PresidentialPardonForm::PresidentialPardonForm(void) : Form()
{
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(other)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		Form::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

/* Member funcs */
void	PresidentialPardonForm::execute(const Bureaucrat& b)
{
	this->throwExecuteException(b);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
