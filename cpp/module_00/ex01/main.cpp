#include <iostream>
#include "PhoneBook.hpp"

int parseInt(std::string input);
std::string	getText();
int getIndex();

int main(void) {
	PhoneBook	phoneBook;
	std::string	input;

	while (1) {
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		
		if (input == "EXIT") {
			std::cout << "EXIT" << std::endl;
			break;
		} else if (input == "ADD") {
			Contact contact;
			std::string firstName;
			std::string lastName;
			std::string nickName;

			std::cout << "First name: " << std::endl;
			contact.setFirstName(getText());

			std::cout << "Last name: " << std::endl;
			contact.setLastName(getText());

			std::cout << "Nick name: " << std::endl;
			contact.setNickName(getText());

			std::cout << "Phone number: " << std::endl;
			contact.setPhoneNumber(getText());

			std::cout << "Darkest secret: " << std::endl;
			contact.setDarkestSecret(getText());

			phoneBook.add(contact);
			std::cout << "ADDED" << std::endl;
		} else if (input == "SEARCH") {
			if (0 == phoneBook.getSize()) {
				std::cout << "No contacts" << std::endl;
				continue;
			}

			phoneBook.show();
			phoneBook.showByIndex(getIndex());
		} else {
			std::cout << "Invalid command" << std::endl;
		}
		
		std::cout << std::endl;
	}
}

int getIndex() {
	int index;

	while (1) {
		std::cout << "Enter an index: ";
		index = parseInt(getText());
		if (index < 0) {
			std::cout << "Index must be between 0 and 7" << std::endl;
		} else {
			break;
		}
	}
	return index;
}

int parseInt(std::string input) {
	if (input.size() != 1) {
		return -1;
	}
	if (!isdigit(input[0])) {
		return -1;
	}

	int index = input[0] - '0';
	if (index < 0 || index > 7) {
		return -1;
	}
	return index;
}

std::string	getText() {
	std::string text;

	while (1) {
		std::cout << "> ";
		std::getline(std::cin, text);
		if (text.length() > 0)
			break;
		std::cout << "Invalid input" << std::endl;
	}
	return text;
}
