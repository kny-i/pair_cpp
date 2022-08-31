#ifndef CPP_ITER_HPP
#define CPP_ITER_HPP
#include <iostream>

template<typename T>
void scale_print(T& arg)
{
	std::cout << arg << std::endl;
}

template <typename T>
void iter(T *array, size_t len, void (*f)(T &)) {
	if (array == NULL || f == NULL) {
		return ;
	}
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}
template <typename T>
void iter(const T *array, size_t len, void (*f)(T &)) {
	if (array == NULL || f == NULL) {
		return ;
	}
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

/* template for test */
template <typename T>
void print(const T &value) {
	std::cout << value << std::endl;
}
template <typename T>
void print(const T value) {
	std::cout << value << " ";
}

#endif //CPP_ITER_HPP
