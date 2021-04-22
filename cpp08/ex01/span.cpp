#include "span.hpp"
#include <stdint.h>


/* Span::Span( void ) : _size( 0 ), _tab(_size, 0), _it(_tab.begin())
{
	std::cout << "Span Default Constructor called" << std::endl;
	return ;
} */

Span::Span( unsigned int const n ) : _size( n ), _idx(0), _tab(_size, 0)
{
	srand(time(NULL));
	std::cout << "Span Parametric Constructor called" << std::endl;
	return ;
}

Span::Span( Span const & src ) : _size( src._size ), _idx(0), _tab(_size, 0)
{
	srand(time(0));
	std::cout << "Span Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Span::~Span()
{
	std::cout << "Span Destructor called" << std::endl;
	return ;
}

int Span::getIdx( void ) const
{
	return this->_idx;
}

void Span::addNumber( int to_add ) throw (std::string const){
	if (_size && _idx < _size)
		_tab[_idx++] = to_add;
	else
		throw std::string ("cannot assign : internal array to small");
	return ;
}

void Span::generate( unsigned int upper_border) throw (std::string const){
	std::vector<int>::iterator it = _tab.begin();
	if (_size >= upper_border)
		for (_idx = 0; _idx < upper_border; ++_idx)
			*it++ = rand();
	else
		throw std::string ("cannot assign : internal array to small");
	return ;
}

int Span::shortestSpan( void ) const throw (std::string const)
{
	if (_idx < 2)
		throw std::string("Cannot find Span while array has not enough elements");
	std::vector<int> tmp(_idx, 0);
	std::copy(_tab.begin(), _tab.begin() + _idx, tmp.begin());
	std::sort(tmp.begin(), tmp.begin() + _idx);
	int last = INT32_MAX;
	int current = INT32_MAX;
	for (size_t i = 0; i < _idx - 1; ++i)
		last = (current = tmp[i + 1] - tmp[i]) < last ? current : last;
	return last;
}

int Span::longestSpan( void ) const throw (std::string const)
{
	if (_idx < 2)
		throw std::string("Cannot find Span while array has not enough elements");
	std::vector<int> tmp(_idx, 0);
	std::copy(_tab.begin(), _tab.begin() + _idx, tmp.begin());
	std::sort(tmp.begin(), tmp.begin() + _idx);
	return tmp[_idx - 1] - tmp[0];
}

void Span::showElem( unsigned int i ) const{
	if (_idx > i)
		std::cout << _tab[i] << std::endl;
	else
		throw std::string("Cannot find element asked : array has not enough elements");	
}

/* void Span::display( void ) const
{
	// std::cout << "avt truc chelou" << std::endl;
	auto print = [](const int& n) { std::cout << n << "\n";};
	// std::cout << "après truc chelou" << std::endl;
	std::for_each(_tab.begin(), _tab.begin() + _idx, print);
} */

Span & Span::operator=( Span const & rhs ) throw (std::string const)
{
	std::cout << "Span Assignment operator called" << std::endl;
	if (this != &rhs ) {
		_size = rhs._size;
		_idx = rhs._idx;
		std::copy(rhs._tab.begin(), rhs._tab.begin() + _idx, _tab.begin());
	}
	else if ( _size < rhs._size )
		throw std::string ("cannot assign : internal array to small");
	return *this;
}

std::ostream & operator<<( std::ostream & o, Span const & i )
{
	o << "The _index : " << i.getIdx();
	return o;
}