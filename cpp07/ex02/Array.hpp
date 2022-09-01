#ifndef CPP_ARRAY_HPP
#define CPP_ARRAY_HPP

#include <iostream>

class Array {
public:
	template <typename T>
	T &operator[](unsigned int index) {
		if (this->arraySize_ < index + 1) {
			throw std::exception();
		}
		return (this->array_[index]);
	}

	template <typename T>
	T const &operator[](unsigned int index) const {
		if (this->arraySize_ < index + 1) {
			throw std::exception();
		}
		return (this->array_[index]);
	}

	/* canonical form */
	Array()
	: arraySize_(0) , array_(new T[0]) {}

	Array(unsigned int value)
	: arraySize_(value), array_(new T[N])) {}

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
		delete [] this->array_;
	}
private:
	unsigned int arraySize_;
	T *array_;
};

template <typename T>
void printArray(Array<T> const &array)
{
	for (size_t i = 0; i < static_cast<int>(array.size()); i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

#endif //CPP_ARRAY_HPP
