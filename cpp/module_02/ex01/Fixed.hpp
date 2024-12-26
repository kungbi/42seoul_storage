#ifndef FIEXED_HPP
# define FIEXED_HPP

#include <iostream>

class Fixed {
private:
	int _flexedPointValue;
	const static int _fractionalBits = 8;
public:
	Fixed(void);
	Fixed(float const raw);
	Fixed(int const raw);
	
	Fixed(const Fixed &src);
	Fixed& operator=(const Fixed &src);
	~Fixed();
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
};
std::ostream& operator<<(std::ostream &out, const Fixed &obj);
# endif