#include "Brain.hpp"
#include "./ex00/Animal.hpp"
#include "./ex00/Cat.hpp"
#include "./ex00/Dog.hpp"

int main()
{
	std::cout << "======[NORMAL CASE DOG CAT]=======" << std::endl;
	Dog *dog = new Dog();
	Cat *cat = new Cat();
	for (size_t i = 0; i < 100; i++) {
		dog->setIdea(i, "Dog");
		const std::string *s = dog->getIdea(i);
		std::cout << "[" << i << "]" << ":"<< *s << std::endl;
	}
	for (size_t i = 0; i < 100; i++) {
		cat->setIdea(i, "Cat");
		const std::string *s = cat->getIdea(i);
		std::cout << "[" << i << "]" << ":"<< *s << std::endl;
	}

	std::cout << "============[OTHER  CASE]=======" << std::endl;
	Dog *hoge = new Dog();
	Cat *fuga = new Cat();
	for (size_t i = 0; i < 100; i++) {
		if (i % 3 == 0) {
			hoge->setIdea(i, "Dog_0");
		} else if (i % 3 == 1) {
			hoge->setIdea(i, "Dog_1");
		} else {
			hoge->setIdea(i, "Dog_2");
		}
		const std::string *s = dog->getIdea(i);
		std::cout << "[" << i << "]" << ":"<< *s << std::endl;
	}
	for (size_t i = 0; i < 100; i++) {
		if (i % 3 == 0) {
			fuga->setIdea(i, "Cat_0");
		} else if (i % 3 == 1) {
			fuga->setIdea(i, "Cat_1");
		} else {
			fuga->setIdea(i, "Cat_2");
		}
		const std::string *s = fuga->getIdea(i);
		std::cout << "[" << i << "]" << ":"<< *s << std::endl;
	}

	delete hoge;
	delete fuga;

	std::cout << "========[ANIMAL CASE]=======" << std::endl;
	Animal *animalDog = new Dog();
	Animal *animalCat = new Cat();

	delete animalDog;
	delete animalCat;

	std::cout << "=========[ABNORMAL INDEX]==========" << std::endl;
	cat->setIdea(104, "INDEX");
	const std::string *str = cat->getIdea(104);
	std::cout << str << std::endl;

	delete dog;
	delete cat;

	std::cout << "=====[COPY CASE]========" << std::endl;
	Cat a;
	Cat b;
	a = b;

	std::cout << "=====[SUBJECT CASE]========" << std::endl;

	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j;
		delete i;

		std::cout << std::endl;
	}
	{
	#define N 10

		Animal *animals[N];
		Dog		*c_dog[N / 2];
		Cat 	*c_cat[N / 2];

		for (size_t i = 0; i < N; i++) {
			if (i % 2 == 0) {
				animals[i] = new Dog();
				c_dog[i] = reinterpret_cast<Dog *>(animals[i % 2]);
//				static_cast<Dog *>(animals[i])->showIdeas();
				c_dog[i]->getIdea(0);
			} else {
				animals[i] = new Cat();
				c_cat[i] = reinterpret_cast<Cat *>(animals[i % 2 + 1]);
				c_cat[i]->getIdea(42);
			}
		}
		for (int i = 0; i < N; i++)
		{
			delete animals[i];
		}
	}
}
