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
	Fixed& operator=(const Fixed &src);
	~Fixed();
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
};
# endif