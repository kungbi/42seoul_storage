#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {
}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY()) {
}

Point &Point::operator=(Point const &src) {
	if (this != &src) {
		// this->_x = src.getX();
		// this->_y = src.getY();
	}
	return *this;
}