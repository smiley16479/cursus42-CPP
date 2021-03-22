#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP
#include <iostream>
#include <string>
#include <array>
#include <iomanip>

class Zombie
{
private:
	int _type;

public:
	Zombie(int type = 1, std::string name = "Sad_unamed_Zombie");
	~Zombie( void );

	std::string _name;
	void advert( void ) const;
	void announce(void) const;
};

#endif