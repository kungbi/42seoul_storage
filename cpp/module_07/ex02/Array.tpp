#include "Array.hpp"

template <typename T>
Array<T>::Array() {
	this->array = new T[0];
	this->n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->array = new T[n];
	this->n = n;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->array;
}

template <typename T>
Array<T>::Array(Array const &array) {
	this->array = new T[array.n];
	this->n = array.n;
	for (unsigned int i = 0; i < this->n; i++)
		this->array[i] = array.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &array) {
	if (this == &array)
		return *this;

	delete[] this->array;
	this->array = new T[array.n];
	this->n = array.n;
	for (unsigned int i = 0; i < this->n; i++)
		this->array[i] = array.array[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= this->n)
		throw OutOfLimitsException();
	return this->array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->n;
}

template <typename T>
const char *Array<T>::OutOfLimitsException::what() const throw() {
	return "Out of limits";
}