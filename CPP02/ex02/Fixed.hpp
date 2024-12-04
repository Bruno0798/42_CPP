#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _value;
	static const int _bits = 8;
public:
	Fixed();
	Fixed(const Fixed &cpy);
	Fixed(int number);
	Fixed(float number);
	~Fixed();

	Fixed &operator=(const Fixed &obj);
	void setRawBits(int raw);
	int getRawBits() const;
	int toInt() const;
	float toFloat() const;

	bool operator>(const Fixed &obj) const;
	bool operator>=(const Fixed &obj) const;
	bool operator<(const Fixed &obj) const;
	bool operator<=(const Fixed &obj) const;
	bool operator==(const Fixed &obj) const;
	bool operator!=(const Fixed &obj) const;
	Fixed operator++();
	Fixed operator++(int);
	int operator--() const;
	Fixed operator--(int);
	Fixed operator+(const Fixed &obj);
	Fixed operator-(const Fixed &obj);
	Fixed operator*(const Fixed &obj) const;
	Fixed operator/(const Fixed &obj);

	static const Fixed &min(const Fixed& frst, const Fixed& scnd);
	static const Fixed &max(const Fixed& frst, const Fixed& scnd);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &obj);

#endif
