//
// Created by 小平波琉 on 2022/08/14.
//

//derived class should be virtual destructor

#ifndef CPP_CAT_HPP
#define CPP_CAT_HPP

#include "Animal.hpp"
#include "../Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	virtual ~Cat();
	Cat(const Animal &rhs);
	Cat &operator=(const Cat &rhs);

	void makeSound() const;

	void setIdea(size_t index, const std::string &idea);
	const std::string *getIdea(size_t index);
private:
	Brain *brain_;
};

#endif //CPP_CAT_HPP
