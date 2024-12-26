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
	for (int i = 0; i < 100; i++) {
		ideas[i] = b.ideas[i];
	}
	return *this;
}

void Brain::setIdea(int i, std::string idea) {
	ideas[i] = idea;
}

std::string Brain::getIdea(int i) const {
	return ideas[i];
}