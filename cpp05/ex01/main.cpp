#include "Form.hpp"
#include "./ex00/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		std::cout << "test-A" << std::endl;
		Bureaucrat 	a("Nakane", 40);
		Form		b;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		b.beSigned(a);
		std::cout << b << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "=====[TEST B]======" << std::endl;
	{
		try {
			Bureaucrat 	yamane("Yamane", 50);
			Form		form;

			std::cout << yamane << std::endl;
			std::cout << form<< std::endl;
			form.beSigned(yamane);
			std::cout << form << std::endl;
		} catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "=====[TEST C]=====" << std::endl;
	{
		try {
			Bureaucrat 	amane("Amane", 80);
			Form		form;

			std::cout << amane << std::endl;
			std::cout << form << std::endl;
			amane.signForm(form);
			std::cout << form << std::endl;
		} catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=====[TEST D]=====" << std::endl;
	{
		try {
			Bureaucrat 	mone("Mone", 20);
			Form		form;

			std::cout << mone << std::endl;
			std::cout << form << std::endl;
			mone.signForm(form);
			std::cout << form << std::endl;
		} catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

