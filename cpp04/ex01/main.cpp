#include "Brain.hpp"
#include "./ex00/Animal.hpp"
#include "./ex00/Cat.hpp"
#include "./ex00/Dog.hpp"

int main()
{
	Dog *dog = new Dog();
	Cat *cat = new Cat();

	dog->setIdea(0, "hoge");
	const std::string *s = dog->getIdea(0);
	std::cout << *s << std::endl;

	delete dog;
	delete cat;
}
