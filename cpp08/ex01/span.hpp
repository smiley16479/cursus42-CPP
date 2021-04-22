#ifndef SPAN_CLASS_H
#define SPAN_CLASS_H

#include <iostream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <deque>

class Span
{
public:
	Span( void );
	Span( unsigned int const n );
	Span( Span const & src );
	~Span( void );

	Span&   operator=( Span const & rhs ) throw (std::string const );

	int getIdx( void ) const;
	void addNumber( int ) throw (std::string const);
	void generate( unsigned int ) throw (std::string const);
	int shortestSpan( void ) const throw (std::string const);
	int longestSpan( void ) const throw (std::string const);
	void showElem( unsigned int ) const;
	// void display( void ) const;

private:

	unsigned int _size;
	unsigned int _idx;
	std::vector<int> _tab;

};

std::ostream &    operator<<( std::ostream & o, Span const & i );

#endif
