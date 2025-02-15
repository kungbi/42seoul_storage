#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::~Intern(void) {
	std::cout << "Intern Destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &intern) {
	if (this == &intern)
		return *this;

	std::cout << "Intern copy Constructor called" << std::endl;
	return *this;
}

Intern::Intern(const Intern &intern) {
	(void)intern;
	std::cout << "Intern copy Constructor called" << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* forms[3] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i];
		}
	}

	throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}