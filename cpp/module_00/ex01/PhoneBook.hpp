#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>

class PhoneBook{
private:
	Contact contact[8];
	int size;
public:
	PhoneBook();
	~PhoneBook();
	void add(Contact contact);
	void show();
};

#endif