#include "Form.hpp"
#include "./ex00/Bureaucrat.hpp"

int	main(void)
{
	std::cout << "=====[TEST A]=====" << std::endl;
	{
		try
		{
			Bureaucrat 	nakane("Nakane", 1);
			Form		form;
			std::cout << nakane << std::endl;
			std::cout << form << std::endl;
			form.beSigned(nakane);
			std::cout << form << std::endl;
		}
		catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
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

