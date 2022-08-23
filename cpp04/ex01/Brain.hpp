//
// Created by 小平波琉 on 2022/08/21.
//

#ifndef CPP_BRAIN_HPP
#define CPP_BRAIN_HPP
#include <iostream>
#include <sstream>

class Brain {
public:
	Brain();
	virtual ~Brain();
	Brain(const Brain &rhs);
	Brain &operator=(const Brain &rhs);

	const std::string *getIdeas() const;
	void printIdeas() const;
private:
	std::string ideas[100];
};

#endif //CPP_BRAIN_HPP
