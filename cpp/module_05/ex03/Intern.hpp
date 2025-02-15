#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
private:

public:
	Intern(void);
	Intern(const Intern &intern);
	Intern &operator=(const Intern &intern);
	~Intern(void);

	AForm *makeForm(std::string formName, std::string target);

	class FormNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif