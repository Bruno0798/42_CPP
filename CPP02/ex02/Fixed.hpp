#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _value;
	static const int _bits = 8;
public:
	Fixed();
	Fixed(Fixed &cpy);
	Fixed(int number);
	Fixed(float number);
	~Fixed();

	Fixed &operator=(const Fixed &obj);
	void setRawBits(int raw);
	int getRawBits() const;
	int toInt() const;
	int toFloat() const;
};


#endif
