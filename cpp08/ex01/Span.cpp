#include "Span.hpp"

Span::Span(unsigned int N) :size(N){

	std::cerr << "Span Constructor called" << std::endl;
	std::cerr << "size is " << getSize() << std::endl;

}
Span::Span() :size(0) {}

Span::Span(const Span &rhs) {

	std::cerr << "Span Copy Constructor called" << std::endl;
	*this = rhs;
}

Span::~Span()
{
	std::cerr << "Span Destructor called" << std::endl;
}
Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		this->size = rhs.size;
		this->vectorStorage = rhs.vectorStorage;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (this->vectorStorage.size() >= this->getSize()){
		throw std::range_error("this vector is already full");
	} else {
		this->vectorStorage.push_back(num);
	}
}

void Span::addRandNumberRange(unsigned int range) {

	srand(time(NULL));
	for(unsigned int i = 0; i < range; i++) {
		if (this->vectorStorage.size() >= this->getSize()){
			throw std::range_error("this vector is already full");
		} else {
			this->vectorStorage.push_back(rand());
		}
	}
}

unsigned int Span::getSize() const {
	return (this->size);
}

unsigned int Span::longestSpan() const {
	if (this->vectorStorage.size() < 2) {
		throw std::range_error("doesn't have enough numbers ");
	} else {
		std::vector<int> tmp(this->vectorStorage);
		std::sort(tmp.begin(), tmp.end());

		std::vector<int>::iterator small = tmp.begin();
		std::vector<int>::iterator big = tmp.end() - 1;
		return (*big - *small);
	}
}

unsigned int Span::shortestSpan() const {
	if (this->vectorStorage.size() < 2) {
		throw std::range_error("doesn't have enough numbers ");
	} else {
		std::vector<int> tmp(this->vectorStorage);
		std::sort(tmp.begin(), tmp.end());

		unsigned int ret = UINT_MAX;
		std::vector<int>::iterator small = tmp.begin();
		std::vector<int>::iterator big = tmp.begin() + 1;
		while (big != tmp.end())
		{
			if (static_cast<unsigned int>(*big - *small) < ret) {
				ret = *big - *small;
			}
			++small;
			++big;
		}
		return (ret);
	}
}

void Span::printValues() const {
	std::vector<int>::const_iterator tmp = this->vectorStorage.begin();
	std::cout << "_________Values_______" << std::endl;
	std::cout << "{";

	for(unsigned int i = 0; i < this->vectorStorage.size(); i++){
		std::cout << *tmp << ',';
		++tmp;
	}
	std::cout << "NULL}" << std::endl;
	std::cout << "______________________" << std::endl << std::endl;
}
