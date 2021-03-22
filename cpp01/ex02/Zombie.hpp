#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP
#include <iostream>
#include <string>
#include <array>
#include <iomanip>

class Zombie
{
private:
	int type;

public:
	Zombie(int type, std::string name);
	~Zombie( void );

	std::string name;
	int advert( void ) const;
};

#endif