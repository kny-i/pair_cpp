#include "Conversion.hpp"

bool Convert::isMultipleSigns()
{
	size_t i = 1;
	std::string str = getValue();
	while (str[i]) {
		if (str[i] == '-' || str[i] == '+') {
			return true;
		}
		i++;
	}
	return false;
}

bool Convert::isMultipleZero()
{
	std::string str = getValue();
	if (((str[0] == '0')
	|| (str[0] == '-' && str[1] == '0')
	|| (str[0] == '+' && str[1] == '0')) && str.size() != 1) {
		return true;
	} else {
		return false;
	}
}

/*
 * ↑副作用が大きすぎた。0.0fのような0から始まる小数のケースも弾いてしまってる。
 * 簡単な.shを書いてあらかじめ予想できるテストが正確に動くかどうかは確かめつつ書くべきだった。
 */

int Convert::parseInput()
{
	if (this->getValue() == "nan" ||
	this->getValue() == "+inf" ||
	this->getValue() == "-inf" ||
	this->getValue() == "+inff" ||
	this->getValue() == "-inff" ||
	this->getValue() == "nanf"){
		return NAN_INF;
	} else if (this->getValue().length() == 1 &&
			 (this->getValue()[0] == '+' ||
			 this->getValue()[0] == '-' ||
			 this->getValue()[0] == 'f' ||
			 this->getValue()[0] == '.')) {
		return CHAR;
	} else if (isMultipleSigns() == true || isMultipleZero() == true) {
		throw Convert::ErrorException();
	} else if (this->getValue().find_first_not_of("+-0123456789") == std::string::npos) {
		return INT;
	} else if (this->getValue().find_first_not_of("+-0123456789.") == std::string::npos) {
		if (this->getValue().find_first_of('.') != this->getValue().find_last_of('.') ||
			isdigit(this->getValue()[this->getValue().find_first_of('.') + 1]) == false ||
			this->getValue().find_first_of('.') == 0){
			return ERROR;
		} else {
			return DOUBLE;
		}
	} else if (this->getValue().find_first_not_of("+-0123456789.f") == std::string::npos) {
		if (this->getValue().find_first_of('f') != this->getValue().find_last_of('f') ||
			this->getValue().find_first_of('.') != this->getValue().find_last_of('.') ||
			this->getValue().find_first_of('f') - this->getValue().find_first_of('.') == 1 ||
			this->getValue().find_first_of('.') == 0 ||
			this->getValue()[this->getValue().find_first_of('f') + 1] != '\0') {
			return ERROR;
		} else {
			return FLOAT;
		}
	} else if ((this->getValue().length() == 1 && std::isprint(this->getValue()[0])) ||
			 (this->getValue().length() == 1 && std::isalpha(this->getValue()[0]))) {
		return CHAR;
	} else {
		return ERROR;
	}
}

/* fromType function */
void Convert::fromChar()
{
	this->charType_ = this->getValue()[0];
	this->intType_ = static_cast<int>(this->getCharType());
	this->floatType_ = static_cast<float>(this->getCharType());
	this->doubleType_ = static_cast<double>(this->getCharType());
}

void Convert::fromInt()
{
	this->intType_ = static_cast<int>(this->getDoubleType());
	this->charType_ = static_cast<char>(this->getIntType());
	this->floatType_ = static_cast<float>(this->getDoubleType());
}

void Convert::fromFloat()
{
	this->floatType_ = static_cast<float>(this->getDoubleType());
	this->charType_ = static_cast<char>(this->getFloatType());
	this->intType_ = static_cast<int>(this->getFloatType());
}

void Convert::fromDouble()
{
	this->charType_ = static_cast<char>(this->getDoubleType());
	this->intType_ = static_cast<int>(this->getDoubleType());
	this->floatType_ = static_cast<float>(this->getDoubleType());
}

void Convert::convertInput()
{
	void (Convert::*functionPTRS[])() =
			{&Convert::fromChar,
			 &Convert::fromInt,
			 &Convert::fromFloat,
			 &Convert::fromDouble};

	this->type_ = Convert::parseInput();
	if (this->getType() == NAN_INF) {
		return ;
	}

	int types[] =
			{CHAR,
			 INT,
			 FLOAT,
			 DOUBLE};
	int i = 0;
	for (; i < 4; i++) {
		if (this->getType() == types[i]) {
			(this->*functionPTRS[i])();
			break ;
		}
	}
	if (i == 4) {
		throw Convert::ErrorException();
	}
}

void	Convert::printValues()
{
	/* [CHAR] */
	if (this->getType() != NAN_INF
	&& (std::numeric_limits<char>::min() <= this->getDoubleType()
	&& this->getDoubleType() <= std::numeric_limits<char>::max())) {
		if (isprint(this->getCharType()) == true) {
			std::cout << "char: '" << this->getCharType() << "'" << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	} else {
		std::cout << "char: impossible" << std::endl;
	}
	/* [INT] */
	if (this->getType() != NAN_INF
	&& (std::numeric_limits<int>::min() <= this->getDoubleType()
	&& this->getDoubleType() <= std::numeric_limits<int>::max())) {
		std::cout << "int: " << this->getIntType() << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}
	/* [FLOAT] */
	if (this->getType() != NAN_INF
	&& (std::numeric_limits<float>::min() <= this->floatType_
	&& this->getFloatType() <= std::numeric_limits<float>::max())) {
		std::cout << "float: " << this->getFloatType();
		if (this->getFloatType() - static_cast<float>(this->getIntType()) == 0) {
			std::cout << ".0f" << std::endl;
		} else {
			std::cout << "f" << std::endl;
		}
	} else {
		if (this->getValue() == "nan" || this->getValue() == "nanf") {
			std::cout << "float: nanf" << std::endl;
		} else if (this->getValue()[0] == '+') {
			std::cout << "float: +inff" << std::endl;
		} else {
			std::cout << "float: -inff" << std::endl;
		}
	}
	/* [DOUBLE] */
	if (this->getType() != NAN_INF) {
		std::cout << "double: " << this->getDoubleType();
		if (this->getDoubleType() - this->getIntType() == 0) {
			std::cout << ".0" << std::endl;
		} else {
			std::cout << std::endl;
		}
	} else {
		if (this->getValue() == "nan" || this->getValue() == "nanf") {
			std::cout << "double: nan" << std::endl;
		} else if (this->getValue()[0] == '+') {
			std::cout << "double: +inf" << std::endl;
		} else {
			std::cout << "double: -inf" << std::endl;
		}
	}
}

/* canonical form */
Convert::Convert(const std::string &value) : value_(value)
{
	this->doubleType_ = atof(this->getValue().c_str());

	this->convertInput();
	this->printValues();
}

Convert::Convert(const Convert &rhs)
{
	*this = rhs;
}

Convert &Convert::operator=(const Convert &rhs) {
	if (this != &rhs) {
		this->value_ = rhs.value_;
	}
	return *this;
}

Convert::~Convert() {}

/* accessor */
const std::string &Convert::getValue() const {
	return value_;
}

void Convert::setValue(const std::string &value) {
	value_ = value;
}

int Convert::getType() const {
	return type_;
}

void Convert::setType(int type) {
	type_ = type;
}

char Convert::getCharType() const {
	return charType_;
}

void Convert::setCharType(char charType) {
	charType_ = charType;
}

int Convert::getIntType() const {
	return intType_;
}

void Convert::setIntType(int intType) {
	intType_ = intType;
}

float Convert::getFloatType() const {
	return floatType_;
}

void Convert::setFloatType(float floatType) {
	floatType_ = floatType;
}

double Convert::getDoubleType() const {
	return doubleType_;
}

void Convert::setDoubleType(double doubleType) {
	doubleType_ = doubleType;
}

//debug
void Convert::debug() const
{
	std::cerr << "========================" << std::endl;
	std::cerr << "int:" << this->getIntType() << std::endl;
	std::cerr << "char:"<< this->getCharType() << std::endl;
	std::cerr << "float:" << this->getFloatType() << std::endl;
	std::cerr << "double:" << this->getDoubleType() << std::endl;
	std::cerr << "========================" << std::endl;
}

//exception
const char *Convert::ErrorException::what() const throw()
{
	return "Error: Impossible to print or input not convertable";
}

