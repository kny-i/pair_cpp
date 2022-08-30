#include "Conversion.hpp"

int Convert::parseInput()
{
	if (this->getValue().compare("nan") == 0 || this->getValue().compare("+inf") == 0 ||
		this->getValue().compare("-inf") == 0 || this->getValue().compare("+inff") == 0 ||
		this->getValue().compare("-inff") == 0)
	{
		return (NAN_INF);
	}
	else if (this->getValue().length() == 1 &&
			 (this->getValue()[0] == '+' || this->getValue()[0] == '-' || // prevents that the input of single digit integers get interpreted as a char
			  this->getValue()[0] == 'f' || this->getValue()[0] == '.'))
	{
		return (CHAR);
	}
	else if (this->getValue().find_first_not_of("+-0123456789") == std::string::npos)//指定された文字列中のいずれの文字にも一致しない最初の場所を検索する。
		return (INT);
	else if (this->getValue().find_first_not_of("+-0123456789.") == std::string::npos)//指定された文字列中のいずれの文字にも一致しない最初の場所を検索する。
	{
		if (this->getValue().find_first_of(".") != this->getValue().find_last_of(".") || // catches `0..0`
			isdigit(this->getValue()[this->getValue().find_first_of(".") + 1]) == false || // catches `0.`
			this->getValue().find_first_of(".") == 0) // catches `.0`
			return (ERROR);
		else
			return (DOUBLE);
	}
	else if (this->getValue().find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (this->getValue().find_first_of("f") != this->getValue().find_last_of("f") || // catches `0.0ff`
			this->getValue().find_first_of(".") != this->getValue().find_last_of(".") || // catches `0..0f`
			this->getValue().find_first_of("f") - this->getValue().find_first_of(".") == 1 || //catches `0.f`
			this->getValue().find_first_of(".") == 0 || // catches `.0f`
			this->getValue()[this->getValue().find_first_of("f") + 1] != '\0') // catches `0.0f0`
			return (ERROR);
		else
			return (FLOAT);
	}
	else if ((this->getValue().length() == 1 && std::isprint(this->getValue()[0])) ||
			 (this->getValue().length() == 1 && std::isalpha(this->getValue()[0])))
	{
		return (CHAR);
	}
	else
		return (ERROR);
}

void Convert::fromChar(void)
{
	this->charType_ = static_cast<unsigned char>(this->getValue()[0]);
	this->intType_ = static_cast<int>(this->getCharType());
	this->floatType_ = static_cast<float>(this->getCharType());
	this->doubleType_ = static_cast<double>(this->getCharType());
}
void Convert::fromInt(void)
{
	this->intType_ = static_cast<int>(this->getDoubleType());
	this->charType_ = static_cast<unsigned char>(this->getIntType());
	this->floatType_ = static_cast<float>(this->getDoubleType());
}
void Convert::fromFloat(void)
{
	this->floatType_ = static_cast<float>(this->getDoubleType());
	this->charType_ = static_cast<char>(this->getFloatType());
	this->intType_ = static_cast<int>(this->getFloatType());
}
void Convert::fromDouble(void)
{
	this->charType_ = static_cast<char>(this->getDoubleType());
	this->intType_ = static_cast<int>(this->getDoubleType());
	this->floatType_ = static_cast<float>(this->getDoubleType());
}

void	Convert::convertInput(void)
{
	void (Convert::*functionPTRS[])(void) = {&Convert::fromChar, &Convert::fromInt, &Convert::fromFloat, &Convert::fromDouble};
	int types[] = {CHAR, INT, FLOAT, DOUBLE};

	this->type_ = Convert::parseInput();

	if (this->getType() == NAN_INF)
		return ;
	int i;
	for (i = 0; i < 4; i++)
	{
		if (this->getType() == types[i])
		{
			(this->*functionPTRS[i])();
			break ;
		}
	}
	if (i == 4)
		throw Convert::ErrorException();
}

const char *Convert::ErrorException::what() const throw()
{
	return ("Error: Impossible to print or input not convertable");
}

void	Convert::printValues(void)const
{
	// display char
	if (this->getType() != NAN_INF)
	{
		if (isprint(this->getCharType()))
			std::cout << "char: '" << this->getCharType() << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	// display int
	if (this->getType() != NAN_INF )
	{
		std::cout << "int: " << this->getIntType() << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;

	// display float
	if (this->getType() != NAN_INF)
	{
		std::cout << "float: " << this->getFloatType();
		if (this->getFloatType() - this->getIntType() == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	else
	{
		if (this->getValue() == "nan" || this->getValue() == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (this->getValue()[0] == '+')
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}

	// display double
	if (this->getType() != NAN_INF)
	{
		std::cout << "double: " << this->getDoubleType();
		if (this->getDoubleType() - this->getIntType() == 0)
		{
			std::cout << ".0" << std::endl;
		}
		else
			std::cout << std::endl;
	}
	else
	{
		if (this->getValue() == "nan" || this->getValue() == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (this->getValue()[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
}

/* canonical form */
Convert::Convert(std::string value) : value_(value)
{
	std::cout << "Conversion Constructor for " << this->getValue() << std::endl;
	this->doubleType_ = std::atof(this->getValue().c_str());
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


