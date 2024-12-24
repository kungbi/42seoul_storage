#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "Fixed::max( a, b ): " << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;

	// const Fixed c(6.1f);
	// Fixed d(5.9f);

	// std::cout << "(c < d): " << (c < d) << std::endl;
	// std::cout << "(c > d): " << (c > d) << std::endl;
	// std::cout << "(c <= d): " << (c <= d) << std::endl;
	// std::cout << "(c >= d): " << (c >= d) << std::endl;

	// std::cout << "(c + d): " << (c + d) << std::endl;
	// std::cout << "(c - d): " << (c - d) << std::endl;
	// std::cout << "(c * d): " << (c * d) << std::endl;
	// std::cout << "(c / d): " << (c / d) << std::endl;
	
	// std::cout << (c / 0) << std::endl;
	// std::cout << (c / Fixed()) << std::endl;


	return 0;
}