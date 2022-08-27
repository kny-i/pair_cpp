#ifndef CPP_INTERN_HPP
#define CPP_INTERN_HPP


#include <iostream>
#include <string>
#include "./ex02/ex01/Form.hpp"
#include "./ex02/RobotomyRequestForm.hpp"
#include "./ex02/PresidentialPardonForm.hpp"
#include "./ex02/ShrubberyCreationForm.hpp"

//class Form;

class Intern {
public:
	class formException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

public:
	Intern();
	~Intern();
	Intern(const Intern &rhs);
	Intern &operator=(const Intern &rhs);

	Form *makeForm(std::string name, std::string target);

	Form *newShrubberyCreationForm(const std::string &target);
	Form *newRobotomyRequestForm(const std::string &target);
	Form *newPresidentialPardonForm(const std::string &target);
};

#endif //CPP_INTERN_HPP
