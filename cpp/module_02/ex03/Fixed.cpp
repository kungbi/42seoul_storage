#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _flexedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed::Fixed(float const raw) {
	this->_flexedPointValue = roundf(raw * (1 << this->_fractionalBits));
}

Fixed::Fixed(int const raw) {
	this->_flexedPointValue = raw << this->_fractionalBits;
}

Fixed& Fixed::operator=(const Fixed &src) {
	if (this != &src)
		this->_flexedPointValue = src.getRawBits();
	return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
	return this->_flexedPointValue;
}

void Fixed::setRawBits(int const raw) {
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

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->_flexedPointValue < obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->_flexedPointValue <= obj.getRawBits());
}

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->_flexedPointValue > obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->_flexedPointValue >= obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->_flexedPointValue != obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->_flexedPointValue == obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	if (obj.getRawBits() == 0) {
		throw std::runtime_error("Division by zero");
	}
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->_flexedPointValue++;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_flexedPointValue--;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed &Fixed::min(Fixed &left, Fixed &right)
{
	return (left < right ? left : right);
}

const Fixed &Fixed::min(Fixed const &left, Fixed const &right)
{
	return (left < right ? left : right);
}

Fixed &Fixed::max(Fixed &left, Fixed &right)
{
	return (left > right ? left : right);
}

const Fixed &Fixed::max(Fixed const &left, Fixed const &right)
{
	return (left > right ? left : right);
}