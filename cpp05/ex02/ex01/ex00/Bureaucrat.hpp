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
	void executeForm(Form const &form);

private:
	const std::string kName_;
	size_t grade_;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

/* colors */
const char *const STOP = "\033[0m";
const char *const BOLD = "\033[1m";
const char *const BLACK = "\033[30m";
const char *const RED = "\033[31m";
const char *const GREEN = "\033[32m";
const char *const YELLOW = "\033[33m";
const char *const BLUE = "\033[34m";
const char *const MAGENTA = "\033[35m";
const char *const CYAN = "\033[36m";
const char *const WHITE = "\033[37m";
const char *const UNDERLINE =" \033[4m";


#endif //CPP_BUREAUCRAT_HPP
