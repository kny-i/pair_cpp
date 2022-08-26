#ifndef CPP_SHRUBBERYCREATIONFORM_HPP
#define CPP_SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "./ex01/ex00/Bureaucrat.hpp"
#include "./ex01/Form.hpp"

class	ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm();

	void	execute(const Bureaucrat& b);

	class ShrubberyFileException : public std::exception{};
};
#endif //CPP_SHRUBBERYCREATIONFORM_HPP
