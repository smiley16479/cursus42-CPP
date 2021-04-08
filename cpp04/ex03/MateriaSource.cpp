#include "MateriaSource.hpp"


MateriaSource::MateriaSource( int matNb ) : _matNb( matNb )
{
	for (size_t i = 0; i < 4; i++)
		_tab[i] = NULL;
	std::cout << "MateriaSource Default Constructor called" << std::endl;
	return ;
}

MateriaSource::MateriaSource( MateriaSource const & src )
{
	std::cout << "MateriaSource Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (size_t i = 0; i < 4; ++i)
		if (_tab[i])
			delete _tab[i];
	return ;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	size_t i = 0;
	if (_matNb != 4)
	{
		for (; _tab[i]; ++i)
			;
		_tab[i] = materia->clone();
	}
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = -1;
	while (i < 4)
		if ( type == _tab[++i]->getType() )
			return _tab[i]->clone();
	return NULL;	
}

AMateria* MateriaSource::invokeMateria( int idx )
{
	return _tab[idx] ;
}

int MateriaSource::getMatNb( void ) const 
{
	return _matNb;
}

MateriaSource & MateriaSource::operator=( MateriaSource const & rhs )
{
	std::cout << "MateriaSource Assignment operator called" << std::endl;
	if (this != &rhs )
		for (size_t i = 0; i < 4; i++) {
			if (_tab[i])
				delete _tab[i];
			_tab[i] = rhs._tab[i]->clone();
		}
	return *this;
}

std::ostream & operator<<( std::ostream & o, MateriaSource const & i )
{
	o << "The _matNb is : " << i.getMatNb();
	return o;
}