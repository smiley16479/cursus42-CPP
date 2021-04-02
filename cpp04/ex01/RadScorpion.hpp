#ifndef RADSCORPION_CLASS_H
#define RADSCORPION_CLASS_H
#include <iostream>
#include "Enemy.hpp"

class RadScorpion : public virtual  Enemy
{
public:
	RadScorpion( void );
	// Si on déclare comme ci-dessous on peut se passer du constructeur par default
	// RadScorpion(std::string _type = "Plasma Rifle", int _hp = 21);
	RadScorpion(std::string _type , int _hp ); 
	RadScorpion( RadScorpion const & src );
	virtual ~RadScorpion( void );
	void takeDamage(int damage);

protected:

};

std::ostream &    operator<<( std::ostream & o, RadScorpion const & i );

#endif
