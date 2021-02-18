/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:53:18 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/02 23:28:00 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>


class Awesome {
public:
Awesome( int n ) : _n( n ) {}
bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
int get_a() {return _n;}
private :
int _n;
};

int main( void ) {
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

///////
std::string e = "elephant";
std::string f = "souris";
std::cout << "e = " << e << ", f = " << f << std::endl;
std::cout << "swap is magic" << std::endl;
::swap(e, f);
std::cout << "e = " << e << ", f = " << f << std::endl;
std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

//float g = 3.14f;
//float h = 2;
Awesome g(12);
Awesome h(4);
std::cout << "g = " << g.get_a()<< ", h = " << h.get_a() << std::endl;
std::cout << "swap is magic" << std::endl;
::swap(g, h);
std::cout << "g = " << g.get_a() << ", h = " << h.get_a() << std::endl;
std::cout << "min( g, h ) = " << ::min( g, h ).get_a()<< std::endl;
std::cout << "max( g, h ) = " << ::max( g, h ).get_a() << std::endl;




return 0;
}
