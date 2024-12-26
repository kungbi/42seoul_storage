#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* dog = new Dog();
	// const Animal animal;
	dog->makeSound();
	delete dog;
	return 0;
}