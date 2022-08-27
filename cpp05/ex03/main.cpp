#include "./ex02/ex01/ex00/Bureaucrat.hpp"
#include "./ex02/ex01/Form.hpp"
#include "./ex02/RobotomyRequestForm.hpp"
#include "./ex02/PresidentialPardonForm.hpp"
#include "./ex02/ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	try {
		Intern someRandomIntern;
		Bureaucrat bureaucrat("test", 4);
		Form* rrf;

		rrf = someRandomIntern.makeForm("robotomy reques", "Bender");
		rrf->execute(bureaucrat);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Intern someRandomIntern;
		Bureaucrat bureaucrat("test", 4);
		Form* rrf;

		rrf = someRandomIntern.makeForm("robotomy_reques", "Bender");
		rrf->execute(bureaucrat);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	{
		std::cout << RED << "_______[PresidentialPardonForm<SUCCESS CASE>]_______"  << STOP << std::endl;
		try {
			Bureaucrat bureaucrat("NOP", 1);
			PresidentialPardonForm form;
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;

			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << RED << "_______[PresidentialPardonForm<FAILURE CASE>]_______" << STOP << std::endl;
		try {
			Bureaucrat bureaucrat("NOP", 30);
			PresidentialPardonForm form;
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;

			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << BLUE<< "_______[RobotomyRequestForm<SUCCESS CASE>]_______"<< STOP << std::endl;
		try {
			Bureaucrat bureaucrat("NOP", 1);
			RobotomyRequestForm form;
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;

			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout<< BLUE << "_______[RobotomyRequestForm<FAILURE CASE>]_______" << STOP<<std::endl;
		try {
			Bureaucrat bureaucrat("NOP", 80);
			RobotomyRequestForm form;
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;

			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << CYAN << "_______[ShrubberyCreationForm<SUCCESS CASE>]_______"<< STOP << std::endl;
		try {
			Bureaucrat bureaucrat("NOP", 1);
			ShrubberyCreationForm form;
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;

			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << CYAN<< "_______[ShrubberyCreationForm<FAILURE CASE>]_______" << STOP<<  std::endl;
		try {
			Bureaucrat bureaucrat("NOP", 300);
			ShrubberyCreationForm form;
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;

			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
