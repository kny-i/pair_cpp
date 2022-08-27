#ifndef CPP_SHRUBBERYCREATIONFORM_HPP
#define CPP_SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>

#include "./ex01/ex00/Bureaucrat.hpp"
#include "./ex01/Form.hpp"

class	ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();

	virtual void execute(const Bureaucrat &executor);

	class ShrubberyFileException : public std::exception{};
};
#endif //CPP_SHRUBBERYCREATIONFORM_HPP
