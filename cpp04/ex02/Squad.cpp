#include "Squad.hpp"

Squad::Squad( int const unitNb/* , ISpaceMarine** ISmTab  */) : _unitNb( unitNb ), _ISmTab( NULL )
{
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

Squad::Squad( Squad const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

Squad::~Squad()
{
	std::cout << "Squad Destructor called" << std::endl;
	for (int i = 0; i < _unitNb; i++)
		delete _ISmTab[i];
	delete [] _ISmTab;
	return ;
}

int Squad::getCount( ) const
{
	return _unitNb;
}

ISpaceMarine* Squad::getUnit(int unit) const
{
	return (_ISmTab[unit]);
}

int Squad::push( ISpaceMarine* ISpm )
{
	ISpaceMarine **tmp = new ISpaceMarine*[_unitNb + 1];
	for (int i = 0; i < _unitNb; ++i)
		tmp[i] = _ISmTab[i];
	tmp[_unitNb] = ISpm;
	if (_ISmTab) {
		// std::cout << _ISmTab << std::endl;
		delete [] _ISmTab;
	}
	_ISmTab = tmp;
	return ++_unitNb;
}

Squad & Squad::operator=( Squad const & rhs )
{
	std::cout << "Squad Assignment operator called" << std::endl;
	if (this != &rhs ) { // delete this
		if (_unitNb) {
			for (int i = 0; i < _unitNb; i++) {
				delete _ISmTab[i];			
				_ISmTab[i] = NULL;
			}
			delete [] _ISmTab;
			_ISmTab = NULL;
		}
		if (rhs._unitNb) { // copy rhs ds this
			_ISmTab = new ISpaceMarine*[rhs._unitNb]; //wtf : new ISpaceMarine*[] ?
			for (int i = 0; i < rhs._unitNb; ++i)
				_ISmTab[i] = rhs._ISmTab[i]->clone();
		}
		_unitNb = rhs._unitNb;
		// _ISmTab = rhs._ISmTab;
	}
	return *this;
}

std::ostream & operator<<( std::ostream & o, Squad const & i )
{
	o << "The _unitNb is : " << i.getCount();
	return o;
}