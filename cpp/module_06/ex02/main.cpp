#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void identify_from_pointer(Base* p);
void identify_from_reference(Base& p);

int main(void) {
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		Base* base = generate();
		identify_from_pointer(base);
		identify_from_reference(*base);
		delete base;

		std::cout << std::endl;
	}

	return 0;
}

Base* generate(void) {
	int random = rand() % 3;

	if (random == 0) {
		return new A();
	} else if (random == 1) {
		return new B();
	} else {
		return new C();
	}
}

void identify_from_pointer(Base* p) {
	std::cout << "Pointer: ";

	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
}

void identify_from_reference(Base& p) {
	std::cout << "Reference: ";

	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::exception& e) {}

	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	} catch (std::exception& e) {}

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	} catch (std::exception& e) {}
}