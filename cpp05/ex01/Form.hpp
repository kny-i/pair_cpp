#ifndef CPP_FORM_HPP
#define CPP_FORM_HPP

#include <iostream>
#include <string>
#include "./ex00/Bureaucrat.hpp"

class Bureaucrat;
class Form {
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
	Form();
	Form &operator=(const Form &rhs);
	Form(const Form &rhs);
	~Form();

	void beSigned(const Bureaucrat &signer);
	const std::string &getKName() const;
	bool isSigned() const;
	void setIsSigned(bool isSigned);
	size_t getKGradeForSign() const;
	size_t getKGradeForExcute() const;

private:
	const std::string kName_;
	bool isSigned_;
	const size_t kGradeForSign_;
	const size_t kGradeForExecute_;
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif //CPP_FORM_HPP
