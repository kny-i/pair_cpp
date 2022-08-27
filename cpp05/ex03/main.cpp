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
}
