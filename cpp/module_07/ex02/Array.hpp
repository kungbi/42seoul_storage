#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
private:
	T *array;
	unsigned int n;
	
public:
	Array();
	Array(unsigned int n);
	Array(Array const &array);
	Array &operator=(Array const &array);
	~Array();

	T &operator[](unsigned int i);
	unsigned int size() const;

	class OutOfLimitsException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

#include "Array.tpp"

#endif