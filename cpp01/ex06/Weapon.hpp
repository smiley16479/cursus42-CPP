#ifndef WEAPON_CLASS_HPP
#define WEAPON_CLASS_HPP
#include <iostream>

class Weapon
{
private:
	std::string _type;

public:
	Weapon( std::string type = "no_weapon");
	~Weapon( void );
	std::string const& getType(void);
	void setType(std::string str);

	// Brain const getBrain( void );
};

#endif