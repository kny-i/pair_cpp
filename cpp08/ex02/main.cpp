#include "MutantStack.hpp"

int	main()
{
	std::cout << "---testSubject---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "____top____" << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "____size___" << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << "__________" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;

	std::cout << "---testSubject---" << std::endl;
	MutantStack<std::string> sstack;
	sstack.push("hoge");
	sstack.push("piyo");
	std::cout << sstack.top() << std::endl;
	sstack.pop();
	std::cout << sstack.size() << std::endl;
	sstack.push("foo");
	sstack.push("fuga");
	sstack.push("nop");
	sstack.push("AKO");
	MutantStack<std::string>::iterator a = sstack.begin();
	MutantStack<std::string>::iterator b = sstack.end();
	++a;
	--a;
	while (a!= b) {
		std::cout << *a<< std::endl;
		++a;
	}
	std::stack<std::string> c(sstack);
	std::cout << std::endl;
}
