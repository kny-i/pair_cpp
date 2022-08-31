
#ifndef CPP_WHATEVER_HPP
#define CPP_WHATEVER_HPP

#include <iostream>
#include "whatever.hpp"

template<typename T>
T min(const T a, const T b) {
	if (a < b) {
		return a;
	} else {
		return b;
	}
}

template<typename T>
T max(const T a, const T b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

template <typename T>
void swap(T &a, T &b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

#endif //CPP_WHATEVER_HPP
