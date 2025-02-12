#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): name(name) {
	this->validateGrade(grade);

	this->grade = grade;
	std::cout << this->name << " Constructor called\n";
}

void Bureaucrat::validateGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : name(bureaucrat.getName()), grade(bureaucrat.getGrade()) {
	std::cout << this->name <<  " copy Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &bureaucrat) {
	if (this == &bureaucrat)
		return *this;

	this->grade = bureaucrat.getGrade();
	std::cout << this->name <<  " copy Constructor called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << this->name << " Destructor called" << std::endl;
}

void Bureaucrat::downGrade(void) {
	if (this->grade >= 150)
		throw GradeTooLowException();

	this->grade++;
}

void Bureaucrat::upGrade(void) {
	if (this->grade <= 1)
		throw GradeTooHighException();

	this->grade--;
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
	} catch (std::exception& e) {
		std::cout << this->name << " cannot sign " << form.getName() << " because " << e.what();
		return;
	}

	std::cout << this->name << " signed " << form.getName() << std::endl;
}

const char  *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Error: Grade is too low\n";
}

const char  *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Error: Grade is too high\n";
}

std::string Bureaucrat::getName(void) const {
	return this->name;
}

int Bureaucrat::getGrade(void) const {
	return this->grade;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}

