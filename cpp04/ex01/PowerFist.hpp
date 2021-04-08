#ifndef POWERFIST_CLASS_H
#define POWERFIST_CLASS_H

#include <iostream>
#include "AWeapon.hpp"


class PowerFist : public AWeapon
{
public:
	PowerFist(std::string _name = "Power Fist", int _damage = 50, int _apcost = 8, std::string _attackOutput = "* pschhh... SBAM ! *");
	PowerFist( PowerFist const & src );
	virtual ~PowerFist( void );

	virtual PowerFist&   operator=( PowerFist const & rhs );

	int getDamage( void ) const;
	virtual void attack() const;

protected:

	// std::string _name; // Dans le classe mère
	// int _damage;
	// int _apcost;
	std::string _attackOutput;

};

std::ostream &    operator<<( std::ostream & o, PowerFist const & i );

#endif
