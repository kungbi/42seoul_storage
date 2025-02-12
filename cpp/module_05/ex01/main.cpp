#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat highBureaucrat("highBureaucrat", 1);
	Bureaucrat lowBureaucrat("lowBureaucrat", 130);
	Form form("form", 75, 150);
	Form form2("form", 75, 150);

	
	std::cout << "====================================\n";
	try {
		std::cout << "[Before]\n" << form << std::endl;
		highBureaucrat.signForm(form);
		highBureaucrat.signForm(form);
		std::cout << "[After]\n" << form << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	
	std::cout << std::endl << "====================================\n";
	try {
		std::cout << "[Before]\n" << form2 << std::endl;
		lowBureaucrat.signForm(form2);
		std::cout << "[After]\n" << form2 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << "====================================\n";
}