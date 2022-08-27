#ifndef CPP_FORM_HPP
#define CPP_FORM_HPP

#include <iostream>
#include <string>
#include "./ex00/Bureaucrat.hpp"

class Bureaucrat;
class Form {
	/* exceptions */
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class UnsignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

public:
	Form();
	Form(const std::string &formName, const size_t gradeForSign, const size_t gradeForExcute, std::string target);
	Form &operator=(const Form &rhs);
	Form(const Form &rhs);
	virtual ~Form();

	void beSigned(const Bureaucrat &signer);
	const std::string &getKName() const;
	bool isSigned() const;
	void setIsSigned(bool isSigned);
	size_t getKGradeForSign() const;
	size_t getKGradeForExcute() const;

	/* new! */
	virtual void execute(const Bureaucrat &executor) const = 0;
	void checkException(const Bureaucrat &executor) const;

	void setTarget(std::string target);
	const std::string  &getTarget() const;

private:
	const std::string kName_;
	bool isSigned_;
	const size_t kGradeForSign_;
	const size_t kGradeForExecute_;

protected:
	std::string target_;
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif //CPP_FORM_HPP
