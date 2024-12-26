#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* animals[10];
	for (int i = 0; i < 10; i++) {
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < 10; i++) {
		animals[i]->makeSound();
		delete animals[i];
	}

	std::cout << std::endl << "-----" << std::endl;
	const Dog* dog = new Dog();
	const Dog* copiedDog = new Dog(*dog);

	dog->getBrain()->setIdea(0, "Idea Idea Idea");
	copiedDog->getBrain()->setIdea(0, "Copied Idea Copied Idea");

	std::cout << "Dog's Brain: " << dog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog's Brain: " << copiedDog->getBrain()->getIdea(0) << std::endl;


	std::cout << std::endl << "-----" << std::endl;
	delete dog;
	delete copiedDog;


	return 0;
}