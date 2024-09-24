#include <iostream>
#include "PhoneBook.hpp"

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

			phoneBook.add(contact);
			std::cout << "ADDED" << std::endl;
		} else if (input == "SHOW") {
			phoneBook.show();
		} else if (input == "SEARCH") {
			phoneBook.show();
		} else {
			std::cout << "Invalid command" << std::endl;
		}
		
		std::cout << std::endl;
	}
}