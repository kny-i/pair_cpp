#include "Form.hpp"

const std::string &Form::getKName() const {
	return kName_;
}

bool Form::isSigned() const {
	return isSigned_;
}

void Form::setIsSigned(bool isSigned) {
	isSigned_ = isSigned;
}

const size_t Form::getKGradeForSign() const {
	return kGradeForSign_;
}

const size_t Form::getKGradeForExcute() const {
	return kGradeForExcute_;
}

std::ostream& operator<<(std::ostream &os, const Form &form)
{
	os << "name : " <<  form.getKName();
	os << "form grade for sign : " << form.getKGradeForSign();
	os << "form grade for excute : " << form.getKGradeForExcute();
	os << "1 is signed, but 0 is unsigned : " << form.isSigned();
	return os;
}
