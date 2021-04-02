#include "Enemy.hpp"


Enemy::Enemy( int hp, std::string const & type ) : _hp( hp ), _type( type )
{
	std::cout << "Enemy Default Constructor called" << std::endl;
	return ;
}

Enemy::Enemy( Enemy const & src )
{
	std::cout << "Enemy Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Enemy::~Enemy()
{
	std::cout << "Enemy Destructor called" << std::endl;
	return ;
}

void Enemy::takeDamage(int damage)
{
	if (_hp - damage < 0)
		_hp = 0;
	else
		_hp -= damage;
}

Enemy & Enemy::operator=( Enemy const & rhs )
{
	std::cout << "Enemy Assignment operator called" << std::endl;
	if (this != &rhs )
	{
		_hp = rhs._hp;
		_type = rhs._type;
	}
	return *this;
}

std::string Enemy::getType() const
{
	return _type;
}

int Enemy::getHP() const
{
	return _hp;
}

std::ostream & operator<<( std::ostream & o, Enemy const & i )
{
	o << i.getType();
	return o;
}