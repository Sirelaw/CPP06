#include "Data.hpp"

Data::Data()
	:  _skill("flight"), _num(42)
{
	_float = 42.22f;
	_char = 'z';
	_double = 34353432233455;
}

Data::Data(const Data& to_copy)
{
	(void) to_copy;
}

Data::~Data()
{
	
}

Data& Data::operator=(const Data& to_assign)
{
	if (this != &to_assign)
	{
		
	}
	return (*this);
}