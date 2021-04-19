#include <iostream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <array>
#include <list>
#include <stack>

template < typename T >
class MutantStack : public std::stack<T> 
{
public:
	MutantStack( void );
	MutantStack( unsigned int const n );
	MutantStack( MutantStack const & src );
	~MutantStack( void );

	class iterator
	{
		public:
			iterator( void );

			//Iterators Préfixés
			iterator&	operator++( void );
			iterator&	operator--( void );
		private:
			std::list<T> _list;
	};

	MutantStack&	operator=( MutantStack const & rhs ) throw (std::string const );

private:
	// std::stack<T> _stack;
};

template < typename T >
std::ostream &    operator<<( std::ostream & o, MutantStack<T> const & i );

template < typename T >
MutantStack<T>::MutantStack( void )
{
	std::cout << "MutantStack Default Constructor called" << std::endl;
	return ;
}

template < typename T >
MutantStack<T>::MutantStack( unsigned int const n )
{
	std::cout << "MutantStack Parametric Constructor called" << std::endl;
	return ;
}

template < typename T >
MutantStack<T>::MutantStack( MutantStack const & src )
{
	std::cout << "MutantStack Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

template < typename T >
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack Destructor called" << std::endl;
	return ;
}

template < typename T >
MutantStack<T> & MutantStack<T>::operator=( MutantStack const & rhs ) throw (std::string const)
{
	std::cout << "MutantStack Assignment operator called" << std::endl;
	if (this != &rhs ) {

	}
	else
		throw std::string ("Smth strange");
	return *this;
}

template < typename T >
MutantStack<T>::iterator::iterator( void )
{
	std::cout << "iterator Default Constructor called" << std::endl;
	return ;
}

template < typename T >
std::ostream & operator<<( std::ostream & o, MutantStack<T> const & i )
{
	o << "The _index : " << i.getIdx();
	return o;
}