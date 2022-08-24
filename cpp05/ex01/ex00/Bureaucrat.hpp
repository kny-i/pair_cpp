//
// Created by 小平波琉 on 2022/08/04.
//

#ifndef CPP_BUREAUCRAT_HPP
#define CPP_BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
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

private:
	const std::string name_;
	size_t grade_;
};

class GradeTooHighException : public std::exception {

};

class GradeTooLowException : public std::exception {

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif //CPP_BUREAUCRAT_HPP
