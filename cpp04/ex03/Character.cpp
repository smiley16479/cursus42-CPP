#include "Character.hpp"


Character::Character( std::string const name ) : _name( name )
{
	for (size_t i = 0; i < 4; ++i)
		_tab[i] = NULL;
	std::cout << "Character Default Constructor called" << std::endl;
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
	for (size_t i = 0; i < 4; i++)
		if (_tab[i])
			delete _tab[i];
	return ;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::getType() const
{
	std::string tmp = "my materia(s) : \n";
	for (size_t i = 0; i < 4; i++)
		if (_tab[i])
			tmp += (_tab[i]->getType() + "\n");
	std::cout << tmp;
	return ;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
		if (!_tab[i]) {
			_tab[i] = m;
			break ;
		}
	return ;
}

void Character::unequip(int idx)
{
	_tab[idx] = NULL;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (_tab[idx])
		_tab[idx]->use(target);
	return ;
}

Character & Character::operator=( Character const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs ) {
		for (size_t i = 0; i < 4; i++) {
			if (_tab[i])
				delete _tab[i];
			_tab[i] = rhs._tab[i]->clone();
		}
		_name = rhs._name;
	}
	return *this;
}

std::ostream & operator<<( std::ostream & o, Character const & i )
{
	o << "I am " << i.getName() << " and my materias are :\n";
	i.getType();
	return o;
}