
#ifndef PAIR_CPP_CONVERSION_HPP
#define PAIR_CPP_CONVERSION_HPP
#include <iostream>
#include <string>

class Convert {
public:
	Convert(std::string value);
	Convert(const Convert &rhs);
	Convert &operator=(const Convert &rhs);
	~Convert();

	/* accessor */
	const std::string &getValue() const;
	void setValue(const std::string &value);
	int getType() const;
	void setType(int type);
	char getCharType() const;
	void setCharType(char charType);
	int getIntType() const;
	void setIntType(int intType);
	float getFloatType() const;
	void setFloatType(float floatType);
	double getDoubleType() const;
	void setDoubleType(double doubleType);

private:
	std::string value_;
	int type_;

	char charType_;
	int intType_;
	float floatType_;
	double doubleType_;
};

#endif //PAIR_CPP_CONVERSION_HPP
