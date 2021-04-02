#ifndef PLASMARIFLE_CLASS_H
#define PLASMARIFLE_CLASS_H

#include <iostream>
#include "AWeapon.hpp"


class PlasmaRifle : public virtual  AWeapon
{
public:
	// PlasmaRifle( void );
	// Si on déclare comme ci-dessous on peut se passer du constructeur par default
	PlasmaRifle(std::string _name = "Plasma Rifle", int _damage = 21, int _apcost = 5, std::string _attackOutput = "* piouuu piouuu piouuu *");
	// PlasmaRifle(std::string _name , int _apcost , int _damage ,std::string _attackOutput );
	PlasmaRifle( PlasmaRifle const & src );
	virtual ~PlasmaRifle( void );

	PlasmaRifle&	operator=( PlasmaRifle const & rhs );

	int getDamage( void ) const;
	virtual void attack() const;
	virtual std::string getName( void ) const;


protected:
	// std::string _name;  // DS la class mère
	// int _damage;
	// int _apcost;
	std::string _attackOutput;

};

std::ostream &	operator<<( std::ostream & o, PlasmaRifle const & i );

#endif
