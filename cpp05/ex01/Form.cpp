#include "Form.hpp"

Form::Form(): kName_("DefaultForm"), isSigned_(false), kGradeForSign_(50), kGradeForExecute_(50)
{
	std::cerr << "(Form constructor called)" << std::endl;
}

Form::Form(const Form &rhs) : kName_(rhs.kName_), isSigned_(false), kGradeForSign_(rhs.getKGradeForSign()), kGradeForExecute_(rhs.getKGradeForExcute())
{
	std::cerr << "(Form copy constructor called)" << std::endl;
}

Form::~Form()
{
	std::cerr << "(Form destructor called)" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	std::cerr << "(assignation operator called)" << std::endl;
	if (this != &rhs) {
		this->isSigned_ = rhs.isSigned();
		const_cast<std::string&>(this->kName_) = rhs.getKName();
		const_cast<size_t &>(this->kGradeForExecute_) = rhs.getKGradeForExcute();
		const_cast<size_t &>(this->kGradeForSign_) = rhs.getKGradeForSign();
	}
	return *this;
}


const std::string &Form::getKName() const
{
	return kName_;
}

bool Form::isSigned() const
{
	return isSigned_;
}

void Form::setIsSigned(bool isSigned)
{
	isSigned_ = isSigned;
}

size_t Form::getKGradeForSign() const
{
	return kGradeForSign_;
}

size_t Form::getKGradeForExcute() const
{
	return kGradeForExecute_;
}

void Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > this->getKGradeForSign()) {
		throw Form::GradeTooHighException();
	} else if (this->isSigned() == true) {
		std::cout << "Form is already signed" << std::endl;
	} else {
		std::cout << "Form is signed by " << signer.getName() << std::endl;
		this->setIsSigned(true);
	}
}

std::ostream& operator<<(std::ostream &os, const Form &form)
{
	std::cout << "__________[Form info]__________" << std::endl;
	os << "name : " <<  form.getKName() << std::endl;
	os << "form grade for sign : " << form.getKGradeForSign() << std::endl;
	os << "form grade for execute : " << form.getKGradeForExcute() << std::endl;
	os << "signed status : " << form.isSigned() << std::endl;
	std::cout << "_______________________________" << std::endl;
	return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "GRADE IS TOO HIGH!!";
}


const char *Form::GradeTooLowException::what() const throw()
{
	return "GRADE IS TOOLOW!!";
}
