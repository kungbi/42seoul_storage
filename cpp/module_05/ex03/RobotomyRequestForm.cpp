#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) 
	:AForm("Robotomy" , 72, 45), target(target) {
	std::cout << this->getName() <<	 " Constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm) 
	:AForm(robotomyRequestForm), target(robotomyRequestForm.getTarget()) {
	std::cout << this->getName() <<	 " copy Constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << this->getName() <<	 " Destructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &robotomyRequestForm) {
	if (this == &robotomyRequestForm)
		return (*this);
	this->target = robotomyRequestForm.getTarget();
	this->AForm::operator=(robotomyRequestForm);
	std::cout <<  " copy Constructor called\n";
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
	this->validateExecutable(executor);
	
	int tmp = (rand() % 2); 

	std::cout << "Drill... Drrr\n";

	if (tmp) {
		std::cout << "wow! " << this->getName() << " succeeded in becoming a robot" << std::endl;
	} else {
		std::cout << "sorry... " << this->getName() << " failed to becoming a robot" << std::endl;
	}
}


std::string RobotomyRequestForm::getTarget(void) const {
	return (this->target);
}