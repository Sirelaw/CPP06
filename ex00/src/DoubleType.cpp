#include "../inc/DoubleType.hpp"
#include <sstream>
#include <stdlib.h>

DoubleType::DoubleType(std::string literal)
	: BaseType(literal)
{
	errno = 0;
	if (_special)
		return ;
	if (_type == CHAR)
		_double_value = _literal[0];
	else
		_double_value = strtod(_literal.c_str(), NULL);
	if (errno == ERANGE)
		throw ImpossibleException();
}

DoubleType::DoubleType(const DoubleType& to_copy)
	: BaseType(to_copy._literal)
{
	*this = to_copy;
}

DoubleType::~DoubleType()
{
	
}

DoubleType& DoubleType::operator=(const DoubleType& to_assign)
{
	if (this != &to_assign)
	{
		_precise = to_assign._precise;
		_special = to_assign._special;
		_value = to_assign._value;
		_type = to_assign._type;
	}
	return (*this);
}