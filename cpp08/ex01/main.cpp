#include "Span.hpp"

int	main()
{
	std::cout << "-----[Basic test]-----" << std::endl;
	Span a = Span(5);
	for (size_t i = 0; i < 6; i++)
	{
		try
		{
			a.addNumber(static_cast<int>(i));
		}
		catch (std::exception &e)
		{
			a.printValues();
			std::cerr << std::endl << e.what() << std::endl;
		}
	}
	std::cout << "shortest span is " << a.shortestSpan() << std::endl;
	std::cout << "longest span is " << a.longestSpan() << std::endl;
	std::cout << std::endl << "-----[Big test]-----" << std::endl << std::endl;
	{
		Span b = Span(10000);
		b.addRondNumberRange(10000);
		//b.printValues();
		std::cout << "shortest span is " << b.shortestSpan() << std::endl;
		std::cout << "longest span is " << b.longestSpan() << std::endl << std::endl;
	}
}

