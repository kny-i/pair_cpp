

#ifndef CPP_FORM_HPP
#define CPP_FORM_HPP

#include <iostream>
#include <string>

class Form {
public:
	Form();
	Form(std::string kName, const size_t kGradeForSign, const size_t kGradeForExcute);

private:
	const std::string kName_;
	bool sign_;
	const size_t kGradeForSign_;
	const size_t kGradeForExcute_;
};

#endif //CPP_FORM_HPP
