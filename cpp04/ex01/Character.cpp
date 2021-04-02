#include "Character.hpp"


Character::Character( int ap, std::string const & name, AWeapon *wp ) : _ap( ap ), _name( name ), _wp( wp )
{
	(void)_ap;
	(void)_name;
	(void)_wp;
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Character::Character( std::string const & name ) :  _ap(40), _name(name), _wp(NULL) 
{
	std::cout << "_name Constructor called" << std::endl;
	return ;
}

Character::Character( Character const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Character::~Character()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void Character::recoverAP()
{
	if (_ap + 10 <= 40)
		_ap += 10;
	return ;
}


void Character::equip(AWeapon* wp)
{
	_wp = wp;
	return ;
}

void Character::attack(Enemy* enemy)
{
	if (enemy && _wp && (_ap - _wp->getAPCost()) >= 0)
	{
		std::cout <<  _name + " attaque " + enemy->getType() + " with a " + _wp->getName() + "\n";
		if ((enemy->getHP() - _wp->getDamage()) > 0)
			enemy->takeDamage(_wp->getDamage());
		else
		{
			delete enemy;
			enemy = NULL;
		}
		_ap -= _wp->getAPCost();
		_wp->attack();
	}
	else
		std::cout <<  _name + " attaque " + enemy->getType() + " with a " + _wp->getName() + "\n";
	return ;
}

std::string Character::getName() const
{
	return _name;
}

Character & Character::operator=( Character const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs )
	{
		_name = rhs._name;
		_ap = rhs._ap;
		_wp = rhs._wp;
	}
	return *this;
}

std::ostream & operator<<( std::ostream & o, Character const & i )
{
	o << i.getName();
	return o;
}