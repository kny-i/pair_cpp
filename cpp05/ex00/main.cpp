#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bureaucrat;
		std::cout << bureaucrat << std::endl;
		bureaucrat.gradeDown();
		std::cout << bureaucrat << std::endl;
		bureaucrat.gradeUp();
		std::cout << bureaucrat << std::endl;
		for (size_t i = 0; i < 43; i++) {
			bureaucrat.gradeUp();
		}
		std::cout << bureaucrat << std::endl;
	} catch (Bureaucrat::GradeTooHighException e) {
		std::cerr << "GRADE IS TOO HIGH " << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException e) {
		std::cerr << "GRADE IS TOO LOW " << e.what() << std::endl;
	} catch (std::exception e) {
		std::cerr << "ERROR" << e.what() << std::endl;
	}
}
