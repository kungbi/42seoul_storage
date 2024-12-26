#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& c) {
	*this = c;
}

WrongCat& WrongCat::operator=(const WrongCat& c) {
	type = c.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}
