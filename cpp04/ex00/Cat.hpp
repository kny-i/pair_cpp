
#ifndef CPP_CAT_HPP
#define CPP_CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &rhs);
	Cat &operator=(const Cat &rhs);

	void makeSound() const;
};

#endif //CPP_CAT_HPP
