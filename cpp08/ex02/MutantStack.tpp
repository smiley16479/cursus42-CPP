#include <iostream>
#include <stack>
#include <stdlib.h>

template < typename T >
class MutantStack : public std::stack<T> 
{
public:
	MutantStack( void );
	MutantStack( MutantStack const & src );
	~MutantStack( void );
	void generate( unsigned int const n );

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(void);
	iterator end(void);

	MutantStack&	operator=( MutantStack<T> const & rhs); /* throw (std::string const );*/

};

template < typename T >
std::ostream &    operator<<( std::ostream & o, MutantStack<T> & i);

template < typename T >
MutantStack<T>::MutantStack( void )
{
	srand(time(0));
	std::cout << "MutantStack Default Constructor called" << std::endl;
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
void MutantStack<T>::generate( unsigned int const n )
{
	for (size_t i = 0; i < n; i++)
		this->push(rand());
	return ;
}

template < typename T >
MutantStack<T> & MutantStack<T>::operator=( MutantStack<T> const & rhs ) /* throw (std::string const) */
{
	std::cout <<  ("MutantStack Assignment operator called");
	if (this != &rhs ) {
		this->std::stack<T>::operator=(rhs);
	}
	else
		throw std::string ("MutantStack Assignment operator failled");
	return *this;
}

template < typename T >
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template < typename T >
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return this->c.end();
}

template < typename T >
std::ostream & operator<<( std::ostream & o, MutantStack<T> & i )
{
	std::stack<T> tmp;
	o << "The complete stack is : \n";
	while (i.size()) {
		o <<  i.top() << std::endl;
		tmp.push(i.top());
		i.pop();
	}
	o << "<<End of stack>>\n";
	while (tmp.size()) {
		i.push(tmp.top());
		tmp.pop();
	}
	return o;
}