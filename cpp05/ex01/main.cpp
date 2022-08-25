#include "Form.hpp"

int	main(void)
{
	{
		try
		{
			std::string	name("John");
			int			grade(2);
			std::cout << "Args: " << name << ", " << grade << std::endl;

			Bureaucrat	bc(name, grade);
			std::cout << bc << std::endl;

			bc--;
			std::cout << bc << std::endl;

			bc++;
			bc++;
			std::cout << bc << std::endl;

			bc++;
			std::cout << bc << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Catched Exception => " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		try
		{
			std::string	name("Kevin");
			int			grade(151);
			std::cout << "Args: " << name << ", " << grade << std::endl;

			Bureaucrat	bc(name, grade);
			std::cout << bc << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Catched Exception => " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		try
		{
			std::string name("OkForm");
			int	gradeSign(50);
			int	gradeExec(10);
			std::cout << "Args: " << name << ", " << gradeSign << ", " << gradeExec << std::endl;
			Form	fmOk(name, gradeSign, gradeExec);
			std::cout << fmOk << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Catched Exception => " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		try
		{
			std::string name("NgForm");
			int	gradeSign(50);
			int	gradeExec(0);
			std::cout << "Args: " << name << ", " << gradeSign << ", " << gradeExec << std::endl;
			Form	fmNg(name, gradeSign, gradeExec);
			std::cout << fmNg << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Catched Exception => " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{

		Bureaucrat	bc("Mark", 20);
		std::cout << bc << std::endl;

		Form	fmOk("OkForm", 50, 10);
		std::cout << fmOk << std::endl;

		bc.signForm(fmOk);
		std::cout << fmOk << std::endl;

		std::cout << std::endl;
	}
	{

		Bureaucrat	bc("Mark", 20);
		std::cout << bc << std::endl;

		Form	fmNg("NgForm", 10, 3);
		std::cout << fmNg << std::endl;

		bc.signForm(fmNg);
		std::cout << fmNg << std::endl;

		std::cout << std::endl;
	}
	return 0;
}
