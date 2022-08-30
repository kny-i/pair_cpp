//
// Created by 小平波琉 on 2022/08/04.
//

#ifndef CPP_WHATEVER_HPP
#define CPP_WHATEVER_HPP

#include <iostream>
#include "whatever.hpp"

template<typename T>
T min(T a, T b) {
	if (a < b) {
		return a;
	} else {
		return b;
	}
}

template<typename T>
T max(T a, T b) {
	if (a < b) {
		return b;
	} else {
		return a;
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
