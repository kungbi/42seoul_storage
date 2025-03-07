#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	:AForm("Presidential" , 25, 5), target(target) {
	std::cout << this->getName() <<	 " Constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm)
	:AForm(presidentialPardonForm), target(presidentialPardonForm.getTarget()) {
	std::cout << this->getName() <<	 " copy Constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << this->getName() <<	 " Destructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &presidentialPardonForm) {
	if (this == &presidentialPardonForm)
		return (*this);
	this->target = presidentialPardonForm.getTarget();
	this->AForm::operator=(presidentialPardonForm);
	std::cout <<  " copy Constructor called\n";
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	this->validateExecutable(executor);
	
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}

std::string PresidentialPardonForm::getTarget(void) const {
	return (this->target);
}