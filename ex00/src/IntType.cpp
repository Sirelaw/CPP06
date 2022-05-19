#include "../inc/IntType.hpp"
#include <sstream>
#include <stdlib.h>

static bool	check_overflow(int value, std::string literal)
{
	if (value == 2147483647)
	{
		if (literal.length() > 10 || (*(literal.end() - 1) != '7'))
			return (true);
	}
	else if (value == -2147483648)
	{
		if (literal.length() > 11 || (*(literal.end() - 1) != '8'))
			return (true);
	}
	return (false);
}

IntType::IntType(std::string literal)
	: BaseType(literal)
{
	if (_type == CHAR)
		_value = _literal[0];
	else
		std::istringstream (_literal) >> _value;
	if (_special || check_overflow(_value, _literal))
		throw ImpossibleException();
}

IntType::IntType(const IntType& to_copy)
	: BaseType(to_copy._literal)
{
	*this = to_copy;
}

IntType::~IntType()
{
	
}

IntType& IntType::operator=(const IntType& to_assign)
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
