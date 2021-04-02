#include "Character.hpp"


Character::Character( int ap, std::string const & name, AWeapon *wp ) : _ap( ap ), _name( name ), _wp( wp )
{
	(void)_ap;
	(void)_name;
	(void)_wp;
	std::cout << "Character Default Constructor called" << std::endl;
	return ;
}

Character::Character( std::string const & name ) :  _ap(40), _name(name), _wp(NULL) 
{
	std::cout << "Character Name Constructor called" << std::endl;
	return ;
}

Character::Character( Character const & src )
{
	std::cout << "Character Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
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

void* Character::getWeapon() const
{
	return _wp;
}

std::string Character::getWeaponName() const
{	
	if (_wp)
		return _wp->getName();
	return 0;
}

int Character::getAp() const
{
	return _ap;
}

Character & Character::operator=( Character const & rhs )
{
	std::cout << "Character Assignment operator called" << std::endl;
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
	if (i.getWeapon())
		o << i.getName() + " has " + std::to_string(i.getAp()) +
		" AP and carries a " + i.getWeaponName() << std::endl;
	else
		o << i.getName() + " has " +  std::to_string(i.getAp()) +
		" AP and is unarmed" << std::endl;
	return o;
}