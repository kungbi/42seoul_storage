#include "Contact.hpp"

Contact::Contact() {
}

std::string Contact::getFirstName() {
	return this->first_name;
}

std::string Contact::getLastName() {
	return this->last_name;
}

std::string Contact::getNickName() {
	return this->nick_name;
}

std::string Contact::getPhoneNumber() {
	return this->phone_number;
}

std::string Contact::getDarkestSecret() {
	return this->darkset_secret;
}

void	Contact::setFirstName(std::string firstName) {
	this->first_name = firstName;
}

void	Contact::setLastName(std::string lastName) {
	this->last_name = lastName;
}

void	Contact::setNickName(std::string nickName) {
	this->nick_name = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	this->phone_number = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darksetSecret) {
	this->darkset_secret = darksetSecret;
}

void	Contact::setAllContact(Contact contact) {
	this->first_name = contact.getFirstName();
	this->last_name = contact.getLastName();
	this->nick_name = contact.getNickName();
	this->phone_number = contact.getPhoneNumber();
	this->darkset_secret = contact.getDarkestSecret();
}
