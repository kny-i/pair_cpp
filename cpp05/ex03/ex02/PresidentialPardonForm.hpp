
#ifndef CPP_PRESIDENTIALPARDONFORM_HPP
#define CPP_PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "./ex01/ex00/Bureaucrat.hpp"
#include "./ex01/Form.hpp"


class PresidentialPardonForm : public Form {

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &rhs);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm(void);

	void execute(const Bureaucrat &executor) const;
};

#endif //CPP_PRESIDENTIALPARDONFORM_HPP
