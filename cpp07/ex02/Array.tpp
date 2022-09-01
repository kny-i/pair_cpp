#ifndef PAIR_CPP_ARRAY_TPP
#define PAIR_CPP_ARRAY_TPP

#include "Array.hpp"
template <typename T>
void printArray(Array<T> const &array)
{
	for (size_t i = 0; i < static_cast<int>(array.size()); i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

//template <typename T>
//std::ostream &operator<<(std::ostream &os, const Array<T> &rhs)
//{
//	for (unsigned int i = 0; i < rhs.size(); i++) {
//		os << "{";
//		if (i > 0) {
//			os << ", ";
//		}
//		os << rhs[i];
//	}
//	os << "}";
//	return os;
//}

#endif //PAIR_CPP_ARRAY_TPP
