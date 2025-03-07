#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : name(name), sign(false), signGrade(signGrade), execGrade(execGrade) {
	this->validate(signGrade, execGrade);

	std::cout << this->name << " Constructor called\n";
}

void Form::validate(int signGrade, int execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &form) : name(form.getName()), sign(form.getSign()), signGrade(form.getSignGrade()), execGrade(form.getExecGrade()) {
	std::cout << this->name <<  " copy Constructor called\n";
}

Form& Form::operator=(Form const &form) {
	if (this == &form)
		return *this;

	this->sign = form.getSign();
	std::cout << this->name <<  " copy Constructor called\n";
	return *this;
}

Form::~Form() {
	std::cout << this->name << " Destructor called\n";
}

std::string Form::getName(void) const {
	return this->name;
}

bool Form::getSign(void) const {
	return this->sign;
}

int Form::getSignGrade(void) const {
	return this->signGrade;
}

int Form::getExecGrade(void) const {
	return this->execGrade;
}

void Form::setSign(bool sign) {
	this->sign = sign;
}

void Form::beSigned(Bureaucrat const &person) {
	if (this->signGrade <= person.getGrade()) 
		throw GradeTooLowException();
	if (sign)
		throw AlreadySignedException();

	sign = true;
}

const char  *Form::GradeTooLowException::what(void) const throw() {
	return "Error: Grade is too low\n";
}

const char  *Form::GradeTooHighException::what(void) const throw() {
	return "Error: Grade is too high\n";
}

const char  *Form::AlreadySignedException::what(void) const throw() {
	return "Error: Form is already signed\n";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form : " << form.getName() << "\nSign : " << form.getSign() << "\nSignGrade : " << form.getSignGrade() << "\nExecgrade : " << form.getExecGrade() << "\n";
	return (out);
}

