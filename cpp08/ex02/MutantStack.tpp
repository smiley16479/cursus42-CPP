#include <iostream>
#include <stack>

template < typename T >
class MutantStack : public std::stack<T> 
{
public:
	MutantStack( void );
	MutantStack( unsigned int const n );
	MutantStack( MutantStack const & src );
	~MutantStack( void );

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(void);
	iterator end(void);
	// MutantStack&	operator=( MutantStack const & rhs ) throw (std::string const );

	MutantStack&	operator=( MutantStack<T> const & rhs ); /* throw (std::string const );
 */
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
	(void)n;
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
MutantStack<T> & MutantStack<T>::operator=( MutantStack<T> const & rhs ) /* throw (std::string const) */
{
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
std::ostream & operator<<( std::ostream & o, MutantStack<T> const & i )
{
	o << "The _index : " << i.getIdx();
	return o;
}