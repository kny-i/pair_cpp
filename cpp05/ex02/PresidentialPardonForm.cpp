#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
		: Form("Default PresidentialPardonForm",
			   25,
			   5,
			   "Default PresidentialPardonForm Target")
{
	std::cerr << "(PresidentialPardonForm default constructor called)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: Form("Default PresidentialPardonForm",
			   25,
			   5,
			   target)
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

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cerr << "(PresidentialPardonForm destructor called)" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	checkException(executor);
	std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
