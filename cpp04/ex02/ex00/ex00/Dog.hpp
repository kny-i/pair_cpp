//
// Created by 小平波琉 on 2022/08/14.
//

#ifndef CPP_DOG_HPP
#define CPP_DOG_HPP
#include "Animal.hpp"
#include "../Brain.hpp"

class Dog : public Animal {
public:
	Dog();
	virtual ~Dog();
	Dog(const Animal &rhs);
	Dog &operator=(const Dog &rhs);

	void makeSound() const;
	void setIdea(size_t index, const std::string &idea);
	const std::string *getIdea(size_t index);
private:
	Brain *brain_;
};

#endif //CPP_DOG_HPP
