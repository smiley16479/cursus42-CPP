#include "MutantStack.hpp"

template < typename T >
MutantStack<T>::MutantStack( void )
{
	std::cout << "MutantStack Default Constructor called" << std::endl;
	return ;
}

template < typename T >
MutantStack<T>::MutantStack( unsigned int const n )
{
	(void)n;
	std::cout << "MutantStack Parametric Constructor called" << std::endl;
	return ;
}

template < typename T >
MutantStack<T>::MutantStack( MutantStack<T> const & src )
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
MutantStack<T> & MutantStack<T>::operator=( MutantStack const & rhs ) throw (std::string const )
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
typename  MutantStack<T>::iterator& MutantStack<T>::iterator::operator++( void )
{
	std::cout << "iterator ++ operator called" << std::endl;
	return ;
} 

template < typename T >
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--( void )
{
	// for (size_t i = 0; i < 2; i++)
	// {
	// 	// this->size()
	// 	this->push(4);
	// }
	std::cout << "iterator -- operator called" << std::endl;
	return ;
}

template < typename T >
void MutantStack<T>::test_mutant( void )
{
	this->m_vector[0];
}

template < typename T >
void MutantStack<T>::iterator::test( void )
{
	std::cout << "iterator test called" << std::endl;
	for (size_t i = 0; i < 2; i++)
	{
		// this->size()
		this->push(4);
	}
}

template < typename T >
std::ostream & operator<<( std::ostream & o, MutantStack<T> const & i )
{
	o << "The _index : " << i.getIdx();
	return o;
}