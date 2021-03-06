#ifndef MUTANTSTACK_CLASS_H
#define MUTANTSTACK_CLASS_H

#include <iostream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <array>
#include <list>
#include <stack>

template < typename T = int >
class MutantStack : public std::stack<T> 
{
public:
	MutantStack( void );
	MutantStack( unsigned int const n );
	void test_mutant( void );
	MutantStack( MutantStack const & src );
	~MutantStack( void );

	class iterator
	{
		public:
			iterator( void );

			//Iterators Préfixés
			iterator&	operator++( void );
			iterator&	operator--( void );
			void	test( void );
		private:
			std::vector<T> i_vector;
	};
	std::vector<T> m_vector;

	MutantStack&	operator=( MutantStack const & rhs ) throw (std::string const );

private:
	// std::stack<T> _stack;
};

template < typename T >
std::ostream &    operator<<( std::ostream & o, MutantStack<T> const & i );

#endif
