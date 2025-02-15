#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Intern intern;


	std::cout << "================ Shrubbery ================\n";
	AForm* scf = intern.makeForm("shrubbery creation", "42seoul");
	std::cout << *scf << "\n";
	delete scf;

	std::cout << "\n================ Robotomy ================\n";
	AForm *rrfe = intern.makeForm("robotomy request", "42seoul");
	std::cout << *rrfe << "\n";
	delete rrfe;

	std::cout << "\n================ Presidential ================\n";
	AForm *ppf = intern.makeForm("presidential pardon", "42seoul");
	std::cout << *ppf << "\n";
	delete ppf;

	try {
		std::cout << "\n================ Unknown ================\n";
		AForm *unknown = intern.makeForm("Unknown", "42seoul");
		std::cout << unknown << "\n";
		delete unknown;
	} catch (const std::exception &e) {
		std::cout << e.what() << "\n";
	}
}