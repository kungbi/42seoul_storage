#include "Fixed.hpp"

class Point {
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point(void);
	Point(const Fixed x, const Fixed y);
	Point(const Point &src);
	Point &operator=(Point const &src);
	~Point();
	Fixed getX(void) const;
	Fixed getY(void) const;
};