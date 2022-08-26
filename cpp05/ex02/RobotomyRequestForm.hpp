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
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	void	execute(const Bureaucrat &b);
};

#endif //CPP_ROBOTOMYREQUESTFORM_HPP
