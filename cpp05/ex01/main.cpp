#include "Form.hpp"
#include "./ex00/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		std::cout << "test-A" << std::endl;
		Bureaucrat a;
		Form		b;

		std::cout << a << std::endl;
		std::cout << b << std::endl;

	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << "catch Grade Too High Exception" << std::endl;
	}


}

