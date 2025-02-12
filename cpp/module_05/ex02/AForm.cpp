#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), sign(false), signGrade(signGrade), execGrade(execGrade) {
	this->validate(signGrade, execGrade);

	std::cout << this->name << " Constructor called\n";
}

void AForm::validate(int signGrade, int execGrade) const {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

void AForm::validateExecutable(Bureaucrat const &executor) const {
	if (!this->sign)
		throw NotSignedException();
	if (this->execGrade < executor.getGrade())
		throw NotEnoughGradeException();
}

AForm::AForm(AForm const &form) : name(form.getName()), sign(form.getSign()), signGrade(form.getSignGrade()), execGrade(form.getExecGrade()) {
	std::cout << this->name <<  " copy Constructor called\n";
}

AForm& AForm::operator=(AForm const &form) {
	if (this == &form)
		return *this;

	this->sign = form.getSign();
	std::cout << this->name <<  " copy Constructor called\n";
	return *this;
}

AForm::~AForm() {
	std::cout << this->name << " Destructor called\n";
}

std::string AForm::getName(void) const {
	return this->name;
}

bool AForm::getSign(void) const {
	return this->sign;
}

int AForm::getSignGrade(void) const {
	return this->signGrade;
}

int AForm::getExecGrade(void) const {
	return this->execGrade;
}

void AForm::setSign(bool sign) {
	this->sign = sign;
}

void AForm::beSigned(Bureaucrat const &person) {
	if (this->signGrade <= person.getGrade()) 
		throw NotEnoughGradeException();
	if (sign)
		throw AlreadySignedException();

	sign = true;
}

const char *AForm::GradeTooLowException::what(void) const throw() {
	return "Error: Grade is too low\n";
}

const char *AForm::GradeTooHighException::what(void) const throw() {
	return "Error: Grade is too high\n";
}

const char *AForm::AlreadySignedException::what(void) const throw() {
	return "Error: Form is already signed\n";
}

const char *AForm::NotSignedException::what(void) const throw() {
	return "Error: Form is not signed\n";
}

const char *AForm::NotEnoughGradeException::what(void) const throw() {
	return "Error: Bureaucrat has not enough grade\n";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << "Form : " << form.getName() << "\nSign : " << form.getSign() << "\nSignGrade : " << form.getSignGrade() << "\nExecgrade : " << form.getExecGrade() << "\n";
	return (out);
}

