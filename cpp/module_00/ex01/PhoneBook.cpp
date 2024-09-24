#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->size = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add(Contact contact) {
	contact.setIndex(this->size);
	this->contact[this->size % 8] = contact;
	size++;
}

void PhoneBook::show() {
	std::cout << "=============================================" << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(10) << "nick name";
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < this->size && i < 8; i++) {
		std::string firstName = this->contact[i].getFirstName();
		std::string lastName = this->contact[i].getLastName();
		std::string nickName = this->contact[i].getNickName();
		if (firstName.length() > 10)
			firstName.replace(9, firstName.length() - 9, ".");
		if (lastName.length() > 10)
			lastName.replace(9, lastName.length() - 9, ".");
		if (nickName.length() > 10)
			nickName.replace(9, nickName.length() - 9, ".");
		std::cout << "|";
		std::cout << std::setw(10) << this->contact[i].getIndex() << "|";
		std::cout << std::setw(10) << firstName << "|";
		std::cout << std::setw(10) << lastName << "|";
		std::cout << std::setw(10) << nickName << "|";
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}