#ifndef MATERIASOURCE_CLASS_H
#define MATERIASOURCE_CLASS_H

#include <iostream>
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
public:
	MateriaSource( int matNb = 0 );
	MateriaSource( MateriaSource const & src );
	~MateriaSource( void );

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
	AMateria* invokeMateria( int idx );
	int getMatNb( void ) const;
	MateriaSource&   operator=( MateriaSource const & rhs );

protected:
	AMateria* _tab[4];
	int _matNb;
};

std::ostream &    operator<<( std::ostream & o, MateriaSource const & i );

#endif
