#include "RobotomyRequestForm.hpp"



/* Caronical */
//RobotomyRequestForm::RobotomyRequestForm() : Form()
//{
//}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {
		Form::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/* Member funcs */
void	RobotomyRequestForm::execute(const Bureaucrat &b)
{
	(void)b;
//	this->throwExecuteException(b);
	std::cout << "\\\\ Bzzzzzzzzzzzzzz //" << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2 == 0) {
		std::cout << "A" << std::endl;
//		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "Sorry, robotomy failed..." << std::endl;
	}
}
