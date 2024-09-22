#include <iostream>
#include "PhoneBook.hpp"

int main(void) {
	PhoneBook	phoneBook;
	std::string	input;

	while (1) {
		std::cout << "Enter a command: ";
		std::cin >> input;
		
		if (input == "EXIT") {
			std::cout << "EXIT" << "\n";
			break;
		} else if (input == "ADD") {
			Contact contact;
			std::string firstName;
			std::string lastName;
			std::string nickName;

			std::cout << "First name: ";
			std::getline(std::cin, firstName);
			contact.setFirstName(firstName);

			std::cout << "Last name: ";
			std::getline(std::cin, lastName);
			contact.setLastName(lastName);

			std::cout << "Nick name: ";
			std::getline(std::cin, nickName);
			contact.setNickName(nickName);

			phoneBook.add(contact);
			std::cout << "ADDED" << "\n";
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