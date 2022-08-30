//
// Created by 小平波琉 on 2022/08/04.
//

#ifndef CPP_ARRAY_HPP
#define CPP_ARRAY_HPP

#include <iostream>
#include "Array.tpp"

class Array {
public:
	/* canonical form */
	Array(unsigned int defaultValue = 0);
	Array(const Array &rhs);
	Array &operator=(const Array &rhs);
	virtual ~Array();
private:
	unsigned int size_;
	T *array_;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &rhs);



#endif //CPP_ARRAY_HPP
