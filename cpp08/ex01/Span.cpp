#include "Span.hpp"

Span::Span(unsigned int N) :size(N){

	std::cout << "Span Constructor called" << std::endl;
	std::cout << "size is " << getSize << std::endl;

}
Span::Span() :size(0){

}
Span::Span(const Span &rhs) {

	std::cout << "Span Copy Constructor called" << std::endl;
	*this = rhs;
}

Span::~Span()
{
	std::cout << "Span Destructor called" << std::endl;
}

void Span::addNumber(int num) {
	if (this->vectorStorage.size() >= this->getSize()){
		throw std::range_error("this vector is already full");
	}
	else {
		this->vectorStorage.push_back(num);
	}
}

void Span::addNumberRange(int num, unsigned int range) {
	for(unsigned int i = 0; i < range; i++) {
		if (this->vectorStorage.size() >= this->getSize()){
			throw std::range_error("this vector is already full");
		}else {
			this->vectorStorage.push_back(num);
		}
	}
}