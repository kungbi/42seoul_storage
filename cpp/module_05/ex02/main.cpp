#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(void) {
    Bureaucrat king("king", 1);
    Bureaucrat woonshin("woonshin", 150);
	ShrubberyCreationForm form("hello");

	king.signForm(form);
	woonshin.executeForm(form);
    std::cout << "[King] : " << king;
    std::cout << "[woonshin] : " << woonshin;

    std::cout << "============= Shrubbery ============" << std::endl;
    ShrubberyCreationForm form1("home");
    std::cout << "[Form]" << std::endl << form1 << std::endl;
    king.signForm(form1);
    king.executeForm(form1);
    woonshin.signForm(form1);
    woonshin.executeForm(form1);
    std::cout << std::endl;

    std::cout << "============= Robotomy ============" << std::endl;
    RobotomyRequestForm form2("home");
    std::cout << "[Form]" << std::endl << form2 << std::endl;
    king.signForm(form2);
    woonshin.signForm(form2);
    king.executeForm(form2);
    woonshin.executeForm(form2);
    std::cout << std::endl;

    std::cout << "============= Presidential ============" << std::endl;
    PresidentialPardonForm form3("home");
    std::cout << "[Form]" << std::endl << form3 << std::endl;
    king.executeForm(form3);
    king.signForm(form3);
    woonshin.signForm(form3);
    king.executeForm(form3);
    woonshin.executeForm(form3);
    std::cout << std::endl;
}