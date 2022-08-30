
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <cstdio>

static Base *generate()
{
	switch (rand() % 3) {
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
		default:
			std::cerr << "rand failure" << std::endl;
			return NULL;
	}
}

static void identify(Base *Test)
{
	if (dynamic_cast<A *>(Test) != NULL) {
		std::cout << "A is the identified type" << std::endl;
	} else if (dynamic_cast<B *>(Test) != NULL) {
		std::cout << "B is the identified type" << std::endl;
	} else if (dynamic_cast<C *>(Test) != NULL) {
		std::cout << "C is the identified type" << std::endl;
	} else {
		std::cout << "unknown type" << std::endl;
	}
}

static int i = 0;
static std::string classes[] = {"A", "B", "C"};

static void identify(Base &Test)
{
	while (i < 3) {
		try {
			if (i == 0) {
				Base &unused = dynamic_cast<A &>(Test);
				(void)unused;
			} else if (i == 1) {
				Base &unused = dynamic_cast<B &>(Test);
				(void)unused;
			} else if (i == 2) {
				Base &unused = dynamic_cast<C &>(Test);
				(void)unused;
			} else {
				std::cout << "unknow type" << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			i++;
			identify(Test);//recursive
			return;
		}
		std::cout << classes[i] << " is the identified type" << std::endl;
		i = 0;
		break;
	}
}

int main()
{
	srand(time(NULL)); // enables the randomness of the generate function
	for (int j = 0; j < 1; j++) {
		Base *Test = generate();
		identify(Test);
		identify(*Test);
		delete (Test);
		std::cout << std::endl;
	}
}

