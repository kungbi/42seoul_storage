#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat normal("A", 75);
		std::cout << normal;
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;
	
	try {
		Bureaucrat high("A", 151);
		std::cout << high;
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;
	
	try {
		Bureaucrat low("A", 0);
		std::cout << low;
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;


	Bureaucrat tmp("A", 1);
	std::cout << tmp;
	tmp.downGrade();
	std::cout << tmp;
	
	return 0;
}