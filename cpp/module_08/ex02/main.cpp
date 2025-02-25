#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl; // -> 17
	
	mstack.pop();

	std::cout << mstack.size() << std::endl; // -> 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite){
		std::cout << *it << std::endl;
		++it;
		// 5, 3, 5, 737, 0
	}
	std::stack<int> s(mstack);


	std::cout << "=========List test=========" << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl; // -> 17

	list.pop_back();

	std::cout << list.size() << std::endl; // -> 1

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator it2 = list.begin();
	std::list<int>::iterator ite2 = list.end();

	++it2;
	--it2;
	while (it2 != ite2){
		std::cout << *it2 << std::endl;
		++it2;
		// 5, 3, 5, 737, 0
	}


	return 0;
}