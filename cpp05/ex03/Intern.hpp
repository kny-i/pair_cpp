

#ifndef CPP_INTERN_HPP
#define CPP_INTERN_HPP
#include <iostream>

class Intern {
	Intern();
	~Intern();
	Intern(const Intern &rhs);
	Intern &operator=(const Intern &rhs);

	Form *makeForm(std::string name, std::string target);
};

#endif //CPP_INTERN_HPP
