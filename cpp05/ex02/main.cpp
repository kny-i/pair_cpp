#include "./ex01/ex00/Bureaucrat.hpp"
#include "./ex01/Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
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
