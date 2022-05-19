#include "../inc/CharType.hpp"
#include <sstream>

CharType::CharType(std::string literal)
	: BaseType(literal)
{
	if (_special)
		throw ImpossibleException();
	if (_type == CHAR)
		_value = _literal[0];
	else
		std::istringstream (_literal) >> _value;
	if (_value < 32 || _value > 127)
		throw NonDisplayableException();
}

CharType::CharType(const CharType& to_copy)
	: BaseType(to_copy._literal)
{
	*this = to_copy;
}

CharType::~CharType()
{
	
}

CharType& CharType::operator=(const CharType& to_assign)
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

const char*	CharType::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}