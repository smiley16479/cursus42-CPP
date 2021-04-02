#ifndef SUPERMUTANT_CLASS_H
#define SUPERMUTANT_CLASS_H
#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public virtual  Enemy
{
public:
	SuperMutant( void );
	// Si on déclare comme ci-dessous on peut se passer du constructeur par default
	// SuperMutant(std::string _type = "Plasma Rifle", int _hp = 21);
	SuperMutant(std::string _type , int _hp );
	SuperMutant( SuperMutant const & src );
	virtual ~SuperMutant( void );
	void takeDamage(int damage);

	SuperMutant&   operator=( SuperMutant const & rhs );

protected:

};

std::ostream &    operator<<( std::ostream & o, SuperMutant const & i );

#endif
