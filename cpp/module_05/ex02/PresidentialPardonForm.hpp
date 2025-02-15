#ifndef PRESIDENTIALPARDONFORM_HPP
# define  PRESIDENTIALPARDONFORM_HPP


#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
	
	PresidentialPardonForm(void);
	
public:
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);
	~PresidentialPardonForm(void);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &presidentialPardonForm);

	std::string getTarget(void) const;
	void execute(Bureaucrat const &executor) const;

};

#endif