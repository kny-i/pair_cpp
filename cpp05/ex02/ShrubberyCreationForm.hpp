

#ifndef CPP_SHRUBBERYCREATIONFORM_HPP
#define CPP_SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class	Bureaucrat;
class	Form;

class	ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm(void);

	void	execute(const Bureaucrat& b);

	class ShrubberyFileException : public std::exception();

};


#endif //CPP_SHRUBBERYCREATIONFORM_HPP
