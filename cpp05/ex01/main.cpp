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

	try
	{
		std::cout << "test-B" << std::endl;
		Bureaucrat 	c("Yamane", 60);
		Form		d;
		std::cout << c << std::endl;
		std::cout << d<< std::endl;
		d.beSigned(c);
		std::cout << d<< std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << "catch Grade Too High Exception" << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << "catch Grade Too Low Exception " << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

}

