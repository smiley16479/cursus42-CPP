#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H

#include <iostream>

class Enemy
{
protected: 
	int _hp;
	std::string _type;

public:
	Enemy(int hp = 100, std::string const & type = "Unknown");
	Enemy( Enemy const & src );
	virtual ~Enemy();

	Enemy & operator=( Enemy const & rhs );

	virtual std::string getType() const;
	int getHP() const;
	virtual void takeDamage(int);
};

std::ostream &    operator<<( std::ostream & o, Enemy const & i );

#endif
