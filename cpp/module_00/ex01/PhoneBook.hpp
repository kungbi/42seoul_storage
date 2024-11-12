#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include "Contact.hpp"
# include <iomanip>

class PhoneBook{
private:
	Contact contact[8];
	int size;
public:
	PhoneBook();
	~PhoneBook();
	void add(Contact contact);
	void show();
	void showByIndex(int index);
	int getSize();
};

#endif