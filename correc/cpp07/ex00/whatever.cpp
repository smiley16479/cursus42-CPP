/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:24:46 by mli               #+#    #+#             */
/*   Updated: 2020/10/13 14:50:24 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template<typename T>
void	swap(T &a, T &b)
{
	T	tmp = b;

	b = a;
	a = tmp;
}

template<typename T>
T const	&min(T const &a, T const &b) { return (a < b ? a : b); }

template<typename T>
T const	&max(T const &a, T const &b) { return (a > b ? a : b); }

template<typename T>
std::string const	DispVar(std::ostream &o, T const &var)
{
	o << "\e[93m" << var << "\e[m";
	return ("");
}

template<typename T>
void	DispSwap(T &a, T &b)
{
	std::cout << "###############################################" << std::endl;
	std::cout << "Swaps	a:" << DispVar(std::cout, a) \
		<< "\tb:" << DispVar(std::cout, b) << std::endl; 
	swap(a, b);
	std::cout << "Swaped	a:" << DispVar(std::cout, a) \
		<< "\tb:" << DispVar(std::cout, b) << std::endl; 
	std::cout << "###############################################" << std::endl;
}

template<typename T>
void	DispCmp(T const &a, T const &b, T const &(*fct)(T const &, T const &), \
		std::string fct_type)
{
	T const &tmp = fct(a, b);
	std::cout << "###############################################" << std::endl;
	std::cout << fct_type << " with a:" << DispVar(std::cout, a) \
		<< " b:" << DispVar(std::cout, b) \
		<< " ==> " << DispVar(std::cout, tmp)  << std::endl;
	std::cout << "Addresses are..." << std::endl;
	std::cout << "- a:\t" << &a << std::endl;
	std::cout << "- b:\t" << &b << std::endl;
	std::cout << "- tmp:\t" << &tmp << std::endl;
	std::cout << "###############################################" << std::endl;
}

#define MAXSTR 0
#define MINSTR 1

int		main(void)
{
	int e = 24; int f = 42;
	int equal_ONE = 30; int equal_TWO = 30;
	std::string str[2] = {"First string", "Second string"};
	const std::string mstr[2] = {"\e[91mmax\e[m", "\e[92mmin\e[m"};

	DispSwap(e, f);
	DispSwap(str[0], str[1]);
	DispSwap<std::string>(str[0], str[1]);

	DispCmp(e, f, max, mstr[MAXSTR]);
	DispCmp(e, f, min, mstr[MINSTR]);

	float fa = 24.24; float fb = 42.42;
	DispCmp(fa, fb, max, mstr[MAXSTR]);
	DispCmp(fa, fb, min, mstr[MINSTR]);

	DispCmp(equal_ONE, equal_TWO, max, mstr[MAXSTR]);
	DispCmp(equal_ONE, equal_TWO, min, mstr[MINSTR]);

	std::cout << "##################### Subject main #######################" << std::endl;
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
	return (0);
}
