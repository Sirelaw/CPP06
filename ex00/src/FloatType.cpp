#include "../inc/FloatType.hpp"
#include <sstream>
#include <stdlib.h>

FloatType::FloatType(std::string literal)
	: BaseType(literal)
{
	errno = 0;
	if (_special)
		return ;
	if (_type == CHAR)
		_float_value = _literal[0];
	else
		_float_value = strtof(_literal.c_str(), NULL);
	if (errno == ERANGE)
		throw ImpossibleException();
}

FloatType::FloatType(const FloatType& to_copy)
	: BaseType(to_copy._literal)
{
	
}

FloatType::~FloatType()
{
	
}

FloatType& FloatType::operator=(const FloatType& to_assign)
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