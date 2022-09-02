#ifndef CPP_SPAN_HPP
#define CPP_SPAN_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <iterator>
#include <climits>
#include <stdexcept>

class Span{
public:
	Span(unsigned int N);
	Span();
	Span(const Span &rhs);
	~Span();
	Span &operator=(const Span &rhs);

	void addNumber(int num);
	void addRandNumberRange(unsigned int range);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	unsigned int getSize() const ;
	void printValues() const;

private:
	std::vector<int> vectorStorage;
	unsigned int size;
};

std::ostream &operator<<(std::ostream &ost, const Span &rhs);

#endif //CPP_SPAN_HPP
