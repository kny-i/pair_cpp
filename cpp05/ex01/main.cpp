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
	} catch (Form::GradeTooHighException &e) {
		std::cerr << "catch Grade Too High Exception" << std::endl;
	}
}

