#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& dog) {
	brain = 0;
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog) {
	if (this == &dog)
		return *this;

	type = dog.type;
	if (brain)
		delete brain;
	brain = new Brain(*(dog.brain));
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}

Brain* Dog::getBrain() const {
	return brain;
}