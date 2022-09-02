#include "Span.hpp"

int	main()
{
	std::cout << "-----[Basic test]-----" << std::endl;
	Span spanA = Span(5);
	for (size_t i = 0; i < 6; i++) {
		try {
			spanA.addNumber(static_cast<int>(i));
		} catch (std::exception &e) {
			spanA.printValues();
			std::cerr << std::endl << e.what() << std::endl;
		}
	}
	std::cout << "shortest spanA is " << spanA.shortestSpan() << std::endl;
	std::cout << "longest spanA is " << spanA.longestSpan() << std::endl;
	std::cout << std::endl << "-----[Big test]-----" << std::endl;
	{
		Span spanB = Span(10000);
		spanB.addRandNumberRange(10000);
		//spanB.printValues();
		std::cout << "shortest spanB is " << spanB.shortestSpan() << std::endl;
		std::cout << "longest spanB is " << spanB.longestSpan() << std::endl << std::endl;
	}

	std::cout << "---------[subject test]-------" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

