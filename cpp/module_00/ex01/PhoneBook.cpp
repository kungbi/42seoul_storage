#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->size = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add(Contact contact) {
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
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << firstName << "|";
		std::cout << std::setw(10) << lastName << "|";
		std::cout << std::setw(10) << nickName << "|";
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::showByIndex(int index) {
	if (index < 0 || index >= this->size) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	std::cout << "first name: " << this->contact[index].getFirstName() << std::endl;
	std::cout << "last name: " << this->contact[index].getLastName() << std::endl;
	std::cout << "nick name: " << this->contact[index].getNickName() << std::endl;
	std::cout << "phone number: " << this->contact[index].getPhoneNumber() << std::endl;
	std::cout << "darkest secret: " << this->contact[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getSize() {
	return this->size;
}