#include <iostream>
#include <string>
#include "whatever.hpp"

template< typename T >
void swap(T & a, T & b) {
	if (a == b)
		return;
	T tmp = a;
	a = b;
	b = tmp;
	return;
}

template< typename T >
T & min(T & a, T & b) {
	if (a == b)
		return b;
	return (a < b ? a : b);
}

template< typename T >
T & max(T & a, T & b) {
	if (a == b)
		return b;
	return (a > b ? a : b);
}

int main(){
/* 
	int		a = 2, b = 3;
	float	c = 2.2, d = 3.3;
	double	e = 2.22, f = 3.33;

	std::cout << "a : " << a << " b : " << b << std::endl;
	std::cout << "swap..." << std::endl;
	swap<int>(a, b); // or swap(c, d);
	std::cout << "a : " << a << " b : " << b << std::endl;
	// std::cout << "c : " << c << " d : " << d << std::endl;

	// Funciotn min(float)
	std::cout << "c : " << c << " d : " << d << " min: " << min(c, d) << std::endl;
	// Funciotn max(double)
	std::cout << "e : " << e << " f : " << f << " max: " << max(e, f) << std::endl;
 */

	// Main fourni
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}