#include "../inc/BaseType.hpp"

bool	BaseType::bad_character(char c, int pos)
{
	std::string			valid;

	if (c == '.')
	{
		int	temp;

		temp = _type;
		_type = DOUBLE;
		return (temp);
	}
	if (pos == BEGIN)
		valid = "-+0123456789";
	else if (pos == MIDDLE)
		valid = "0123456789";
	else
	{
		if (c == 'f')
			_type = FLOAT;
		if (*(_literal.begin() + 1) == 'f' && !isdigit(*(_literal.begin())))
			return (true);
		valid = "0123456789f";
	}
	for(std::string::iterator iter = valid.begin(); iter < valid.end(); iter++)
	{
		if (*iter == c)
			return (false);
	}
	return (true);
}

static int check_special(std::string& literal, int& type, bool& special)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf"
		|| literal == "-inf" || literal == "+inf" || literal == "nan")
	{
		if (literal == "-inff" || literal == "+inff" || literal == "nanf")
			type = FLOAT;
		else
			type = DOUBLE;
		special = true;
	}
	return (type);
}

static int	check_len(std::string& literal, int& type)
{
	std::string::iterator	iter;
	int						len;

	len = literal.length();
	if (len == 1)
	{
		iter = literal.begin();
		if (isdigit(*iter))
			type = INT;
		else
			type = CHAR;
	}
	return (len);
}

BaseType::BaseType(std::string literal)
	: _literal(literal), _precise(1), _special(false),
		_value(0), _double_value(0), _float_value(0), _type(0)
{
	if (check_special(literal, _type, _special))
		return ;
	if (check_len(literal, _type) == 1)
		return ;
	for(std::string::iterator iter = literal.begin(); iter < literal.end(); iter++)
	{
		if (iter == literal.begin() && bad_character(*iter, BEGIN))
			throw	BaseType::WrongInputException();
		else if (iter == literal.end() - 1 && bad_character(*iter, END))
			throw	BaseType::WrongInputException();
		else if (iter != literal.begin() && (iter != literal.end() - 1) && bad_character(*iter, MIDDLE))
			throw	BaseType::WrongInputException();
		if (*iter == '.')
			_precise = literal.end() - iter;
	}
	if (!_type)
		_type = INT;
}

BaseType::BaseType(const BaseType& to_copy)
	: _literal(to_copy._literal)
{
	*this = to_copy;
}

BaseType::~BaseType()
{
	
}

BaseType& BaseType::operator=(const BaseType& to_assign)
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

std::string	BaseType::getType() const
{
	std::string	type[5];

	type[CHAR] = "CHAR"; 
	type[INT] = "INT"; 
	type[FLOAT] = "FLOAT"; 
	type[DOUBLE] = "DOUBLE"; 
	return (type[_type]);
}

bool	BaseType::getSpecial() const
{
	return (_special);
}

int	BaseType::getValue() const
{
	return (_value);
}

int	BaseType::getPrecise() const
{
	return (_precise);
}

double	BaseType::getDoubleValue() const
{
	return (_double_value);
}

float	BaseType::getFloatValue() const
{
	return (_float_value);
}

std::string	BaseType::getLiteral() const
{
	std::string	literal;

	literal = _literal;
	if (_type == FLOAT)
		literal.pop_back();
	return (literal);
}

const char*	BaseType::WrongInputException::what() const throw()
{
	return ("WrongInputException");
}

const char*	BaseType::ImpossibleException::what() const throw()
{
	return ("impossible");
}
