
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

static void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << "A is the identified type" << std::endl;
	} else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << "B is the identified type" << std::endl;
	} else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << "C is the identified type" << std::endl;
	} else {
		std::cout << "unknown type" << std::endl;
	}
}

static int i = 0;
static std::string classes[] = {"A", "B", "C"};

static void identify(Base &p)
{
	while (i < 3) {
		try {
			if (i == 0) {
				Base &unused = dynamic_cast<A &>(p);
				(void)unused;
			} else if (i == 1) {
				Base &unused = dynamic_cast<B &>(p);
				(void)unused;
			} else if (i == 2) {
				Base &unused = dynamic_cast<C &>(p);
				(void)unused;
			} else {
				std::cout << "unknow type" << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			i++;
			identify(p);//recursive
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
		Base *p = generate();
		identify(p);
		identify(*p);
		delete (p);
		std::cout << std::endl;
	}
}

