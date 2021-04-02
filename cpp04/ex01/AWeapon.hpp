#ifndef AWEAPON_CLASS_H
#define AWEAPON_CLASS_H

#include <iostream>

class AWeapon
{
protected:
		std::string _name;
		int _apcost;
		int _damage;

public:
	AWeapon();
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon( AWeapon const & src );
	virtual ~AWeapon( void );

	virtual AWeapon&   operator=( AWeapon const & rhs );

	virtual std::string getName( void ) const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
};

std::ostream &    operator<<( std::ostream & o, AWeapon const & i );

#endif
