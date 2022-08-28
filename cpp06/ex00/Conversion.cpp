//
// Created by 小平波琉 on 2022/08/28.
//

#include "Conversion.hpp"
/* canonical form */
Convert::Convert(std::string input) : value_(input) {}


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


