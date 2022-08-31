
#ifndef PAIR_CPP_CONVERSION_HPP
#define PAIR_CPP_CONVERSION_HPP
#include <iostream>
#include <string>

enum {
	NAN_INF = 1,
	ERROR = 2,
	CHAR = 3,
	INT = 4,
	FLOAT = 5,
	DOUBLE = 6
};

class Convert {
public:
	int	parseInput();
	void convertInput();
	void printValues();
	bool isMultipleSigns();

	/* fromType functions */
	void fromChar();
	void fromInt();
	void fromFloat();
	void fromDouble();

	//debug
	void debug() const;

	/* canonical form */
	Convert(const std::string &value);
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
	bool isMultipleZero();


	class ErrorException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	std::string value_;
	int type_;

	char charType_;
	int intType_;
	float floatType_;
	double doubleType_;
};

//long long ft_atoll(char *str);

#endif //PAIR_CPP_CONVERSION_HPP

