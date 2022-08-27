#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
		: Form("Default RobotomyRequestForm",
			   72,
			   45,
			   "Default RobotomyRequestForm target")
{
	std::cerr << "(Default RobotmyRequestForm default constructor called)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: Form("Default RobotomyRequestForm",
			   72,
			   45,
			   target)
{
	std::cerr << "(Default RobotmyRequestForm constructor called)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : Form(rhs)
{
	std::cerr << "(RobotmyRequestForm copy constructor called)" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs) {
		Form::operator=(rhs);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cerr << "(RobotmyRequestForm destructor called)" << std::endl;
}

/* Member funcs */
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	checkException(executor);
	std::cout << "[DRILLING NOISES]\\\\ Bzzzzzzzzzzzzzz //" << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2 == 0) {
		std::cout  << this->getTarget() << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "Sorry, robotomy failed..." << std::endl;
	}
}
