#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& c) {
	brain = new Brain();
	*this = c;
}

Cat& Cat::operator=(const Cat& c) {
	type = c.type;
	if (brain)
		delete brain;
	brain = new Brain(*c.brain);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}

Brain* Cat::getBrain() const {
	return brain;
}
