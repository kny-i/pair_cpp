#include "Form.hpp"

Form::Form(): kName_("default"), isSigned_(false), kGradeForSign_(50), kGradeForExcute_(50)
{
	std::cerr << "(Form constructor called)" << std::endl;
}

Form::Form(const Form &rhs):kName_(rhs.kName_), isSigned_(false), kGradeForSign_(rhs.getKGradeForSign()), kGradeForExcute_(rhs.getKGradeForExcute())
{
	std::cerr << "(Form Copy constructor called)" << std::endl;
}

Form::~Form()
{
	std::cerr << "(Form Deconstructor called)" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	std::cerr << "(assignation operator called)" << std::endl;
	if (this != &rhs) {
		this->isSigned_ = rhs.isSigned();
		const_cast<std::string&>(this->kName_) = rhs.getKName();
		const_cast<size_t &>(this->kGradeForExcute_) = rhs.getKGradeForExcute();
		const_cast<size_t &>(this->kGradeForSign_) = rhs.getKGradeForSign();
	}
	return *this;
}

const std::string &Form::getKName() const {
	return kName_;
}

bool Form::isSigned() const {
	return isSigned_;
}

void Form::setIsSigned(bool isSigned) {
	isSigned_ = isSigned;
}

size_t Form::getKGradeForSign() const {
	return kGradeForSign_;
}

size_t Form::getKGradeForExcute() const {
	return kGradeForExcute_;
}

std::ostream& operator<<(std::ostream &os, const Form &form)
{
	std::cout << "----------Form info ----------" << std::endl;
	os << "name : " <<  form.getKName() << std::endl;
	os << "form grade for sign : " << form.getKGradeForSign() << std::endl;
	os << "form grade for excute : " << form.getKGradeForExcute() << std::endl;
	os << "1 is signed, but 0 is unsigned : " << form.isSigned() << std::endl;
	std::cout << "-------------------------------" << std::endl;
	return os;
}

