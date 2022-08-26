
#ifndef CPP_PRESIDENTIALPARDONFORM_HPP
#define CPP_PRESIDENTIALPARDONFORM_HPP



# include <iostream>
# include "./ex01/ex00/Bureaucrat.hpp"
# include "./ex01/Form.hpp"

//class	Bureaucrat;
//class	Form;

class PresidentialPardonForm : public Form {

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm(void);

	void	execute(const Bureaucrat& b);
};

#endif //CPP_PRESIDENTIALPARDONFORM_HPP
