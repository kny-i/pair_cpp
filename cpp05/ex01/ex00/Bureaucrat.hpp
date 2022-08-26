#ifndef CPP_BUREAUCRAT_HPP
#define CPP_BUREAUCRAT_HPP

#include <iostream>
#include "../Form.hpp"

class Form;

class Bureaucrat {
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();

	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

public:
	Bureaucrat();
	Bureaucrat(std::string name, size_t grade);
	Bureaucrat(const Bureaucrat &rhs);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &rhs);

	void gradeUp();
	void gradeDown();

	const std::string &getName() const;
	size_t getGrade() const;
	void setGrade(size_t grade);
	void signForm(Form &form);

private:
	const std::string kName_;
	size_t grade_;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif //CPP_BUREAUCRAT_HPP
