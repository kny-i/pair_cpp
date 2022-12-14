
#ifndef CPP_DOG_HPP
#define CPP_DOG_HPP
#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);

	void makeSound() const;
};

#endif //CPP_DOG_HPP
