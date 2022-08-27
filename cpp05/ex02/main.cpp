#include "./ex01/ex00/Bureaucrat.hpp"
#include "./ex01/Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		std::cout << "_______[PresidentialPardonForm<SUCCESS CASE>]_______" << std::endl;
		try {
			Bureaucrat bureaucrat("NOP", 1);
			PresidentialPardonForm form;
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;

			form.beSigned(bureaucrat);
			form.execute(bureaucrat);

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "_______[RobotomyRequestForm<SUCCESS CASE>]_______" << std::endl;
		try {
			Bureaucrat bureaucrat("NOP", 1);
			RobotomyRequestForm form;
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;

			form.beSigned(bureaucrat);
			form.execute(bureaucrat);

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "_______[ShrubberyCreationForm<SUCCESS CASE>]_______" << std::endl;
		try {
			Bureaucrat bureaucrat("NOP", 1);
			ShrubberyCreationForm form;
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;

			form.beSigned(bureaucrat);
			form.execute(bureaucrat);

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
