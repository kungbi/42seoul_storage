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

Cat::Cat(const Cat& cat): Animal(cat) {
	brain = new Brain(*cat.brain);
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	if (this == &cat)
		return *this;

	type = cat.type;
	if (brain)
		delete brain;
	brain = new Brain(*cat.brain);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}

Brain* Cat::getBrain() const {
	return brain;
}
