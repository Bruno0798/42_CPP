#include "Fixed.hpp"

Fixed::Fixed() : _value()
{
	std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = cpy;
}

Fixed::Fixed(const int number) : _value(number << _bits)
{
	std::cout << "Int Constructor Called" << std::endl;
}

Fixed::Fixed(float number) : _value(roundf(number * (1 << _bits)))
{
	std::cout << "Float Constructor Called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy Assignment Called" << std::endl;

	if (this == &obj)
		return *this;

	_value = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits Member Function Called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits Member Function Called" << std::endl;
	_value = raw;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << _bits);
}

int Fixed::toInt() const
{
	return _value >> _bits;
}

bool Fixed::operator>(const Fixed &obj) const
{
	return _value > obj._value;
}

bool Fixed::operator<(const Fixed &obj) const
{
	return _value < obj._value;
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return _value >= obj._value;
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return _value <= obj._value;
}

bool Fixed::operator==(const Fixed &obj) const
{
	return _value == obj._value;
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return _value != obj._value;
}

Fixed Fixed::operator++()
{
	this->_value = _value + 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	_value++;
	return tmp;
}

Fixed Fixed::operator--()
{
	_value = _value - 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	_value--;
	return tmp;
}

Fixed Fixed::operator+(const Fixed &obj)
{
	_value += obj._value;
	return *this;
}

Fixed Fixed::operator-(const Fixed &obj)
{
	_value -= obj._value;
	return *this;
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj)
{
	if(obj._value == 0)
	{
		std::cout << "Can't divide by 0" << std::endl;
		return Fixed();
	}
	_value /= obj._value;
	return *this;
}

const Fixed &Fixed::min(const Fixed& frst, const Fixed& scnd)
{
	if(frst < scnd)
		return frst;
	return scnd;
}

const Fixed &Fixed::max(const Fixed& frst, const Fixed& scnd)
{
	if(frst > scnd)
		return frst;
	return scnd;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}