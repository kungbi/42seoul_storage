#include "Fixed.hpp"

Fixed::Fixed(void) : _flexedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(float const raw) {
	std::cout << "Float constructor called" << std::endl;
	this->_flexedPointValue = roundf(raw * (1 << this->_fractionalBits));
}

Fixed::Fixed(int const raw) {
	std::cout << "Int constructor called" << std::endl;
	this->_flexedPointValue = raw << this->_fractionalBits;
}

Fixed& Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_flexedPointValue = src.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_flexedPointValue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_flexedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_flexedPointValue / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_flexedPointValue >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}