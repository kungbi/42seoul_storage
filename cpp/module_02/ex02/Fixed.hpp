#ifndef FIEXED_HPP
# define FIEXED_HPP

#include <iostream>

class Fixed {
private:
	int _flexedPointValue;
	const static int _fractionalBits = 8;
public:
	Fixed(void);
	Fixed(const Fixed &src);
	Fixed(float const raw);
	Fixed(int const raw);
	Fixed& operator=(const Fixed &src);
	~Fixed();
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;

	bool operator<(const Fixed &obj) const;
	bool operator<=(const Fixed &obj) const;
	bool operator>(const Fixed &obj) const;
	bool operator>=(const Fixed &obj) const;
	bool operator!=(const Fixed &obj) const;
	bool operator==(const Fixed &obj) const;

	Fixed operator+(const Fixed &obj) const;
	Fixed operator-(const Fixed &obj) const;
	Fixed operator*(const Fixed &obj) const;
	Fixed operator/(const Fixed &obj) const;

	Fixed	&operator++(void);
	const Fixed	operator++(int);
	Fixed	&operator--(void);
	const Fixed	operator--(int);

	static Fixed	&min(Fixed &left, Fixed &right);
	static const Fixed	&min(Fixed const &left, Fixed const &right);
	static Fixed	&max(Fixed &left, Fixed &right);
	static const Fixed	&max(Fixed const &left, Fixed const &right);
};
std::ostream& operator<<(std::ostream &out, const Fixed &obj);
# endif