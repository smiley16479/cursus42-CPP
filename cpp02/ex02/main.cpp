#include <iostream>
#include "Fixed.class.hpp"

int main(void)
{
	Fixed a(20);
	Fixed c(2);
	Fixed const b(Fixed(2.5f) * Fixed(2));
	

	std::cout << (a < c) << std::endl;
	std::cout << Fixed::min(a, c) << std::endl;
	std::cout << Fixed::max((const Fixed&)a, (const Fixed&)c) << std::endl;

	std::cout << "a * b => " << a * b << std::endl;
	std::cout << "a / b => " << a / b << std::endl;
	std::cout << "a * b => " << std::endl;
	std::cout << "a => " << a << std::endl;
	std::cout << "++a => " << ++a << std::endl;
	std::cout << "a b => " << a << std::endl;
	std::cout << "a++ => " << a++ << std::endl;
	std::cout << "a => " << a << std::endl;
	std::cout << "b => " << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	return 0;
}