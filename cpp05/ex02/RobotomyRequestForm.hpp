#ifndef CPP_ROBOTOMYREQUESTFORM_HPP
#define CPP_ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "./ex01/ex00/Bureaucrat.hpp"
#include "./ex01/Form.hpp"

class	RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &rhs);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();

	virtual void execute(const Bureaucrat &executor) const;
};

#endif //CPP_ROBOTOMYREQUESTFORM_HPP
