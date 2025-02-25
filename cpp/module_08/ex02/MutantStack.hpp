#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const & src) : std::stack<T>(src) {}
	~MutantStack() {}

	MutantStack & operator=(MutantStack const & src) {
		if (this != &src)
			std::stack<T>::operator=(src);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() {
		return std::stack<T>::c.begin();
	}

	iterator end() {
		return std::stack<T>::c.end();
	}
};

#endif