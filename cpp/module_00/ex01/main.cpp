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
			std::cout << "Not a number" << std::endl;
		} else {
			break;
		}
	}
	return index;
}

int parseInt(std::string input) {
	for (size_t i = 0; i < input.size(); i++) {
		if (!std::isdigit(input[i]))
			return -1;
	}
	return std::stoi(input);
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
