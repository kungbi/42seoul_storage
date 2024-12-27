#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& b) {
	*this = b;
}

Brain& Brain::operator=(const Brain& b) {
	if (this == &b) {
		return *this;
	}

	for (int i = 0; i < 100; i++) {
		ideas[i] = b.ideas[i];
	}
	return *this;
}

void Brain::setIdea(int i, std::string idea) {
	if (!(0 <= i && i < 100)) {
		std::cout << "Invalid index" << std::endl;
		return;
	}

	ideas[i] = idea;
}

std::string Brain::getIdea(int i) const {
	if (!(0 <= i && i < 100)) {
		std::cout << "Invalid index" << std::endl;
		return "";
	}
	
	return ideas[i];
}