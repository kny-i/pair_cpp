#ifndef CPP_ARRAY_HPP
#define CPP_ARRAY_HPP

#include <iostream>
#include "Array.tpp"

class Array {
public:
	/* canonical form */
	Array() : arraySize_(0) {}

	Array(unsigned int value)
	: arraySize_(value), array_(new T()) {}

	Array(const Array &rhs) {
		*this = rhs;
	}

	Array &operator=(const Array &rhs) {
		if (this != rhs) {
			this->arraySize_ = rhs.arraySize_;
			this->array_ = new T[this->arraySize_];
			for (unsigned int i = 0; i < this->arraySize_; i++) {
				this->array_[i] = rhs.array_[i];
			}
		}
		return *this;
	}

	virtual ~Array() {
		delete [] array;
	}
private:
	unsigned int arraySize_;
	T *array_;
};

template <typename T>
T const &operator[](unsigned int index) const {

}
//↑const verと両方作るべき

//template <typename T>
//std::ostream &operator<<(std::ostream &os, const Array<T> &rhs);


#endif //CPP_ARRAY_HPP
