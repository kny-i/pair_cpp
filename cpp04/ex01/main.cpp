#include "Brain.hpp"
#include "./ex00/Animal.hpp"
#include "./ex00/Cat.hpp"
#include "./ex00/Dog.hpp"

int main()
{
//	Brain brain;
//	brain.setIdea(0, "hello");
//	const std::string *idea = brain.getIdea(0);
//	std::cout << *idea << std::endl;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();



	delete dog;
	delete cat;
}
