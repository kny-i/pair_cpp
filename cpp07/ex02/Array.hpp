#ifndef CPP_ARRAY_HPP
#define CPP_ARRAY_HPP

#include <iostream>
template<typename T>
class Array {
public:
	T &operator[](unsigned int index) {
		if (this->arraySize_ < index + 1) {
			throw std::exception();
		}
		return (this->array_[index]);
	}

	T const &operator[](unsigned int index) const {
		if (this->arraySize_ <= index) {
			throw std::exception();
		}
		return (this->array_[index]);
	}

	unsigned int size() const
	{
		return this->arraySize_;
	}
	/* canonical form */
	Array()
	: arraySize_(0) , array_(new T[0]) {}

		Array(unsigned int value)
	: arraySize_(value), array_(new T[value]) {}

	Array(const Array &rhs) {
		*this = rhs;
	}

	Array &operator=(const Array &rhs) {
		if (this->array_ != NULL)
		{
			delete [] this->array_;
		}
		if (this != &rhs) {
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

/*

void printArray(Array<T> const &array)
{
	for (size_t i = 0; i < static_cast<int>(array.size()); i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
*/
#endif //CPP_ARRAY_HPP
