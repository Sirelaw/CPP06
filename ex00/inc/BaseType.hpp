#ifndef BASETYPE_HPP
#define BASETYPE_HPP

#include <iostream>
#include <string>

enum
{
	CHAR = 1,
	INT,
	FLOAT,
	DOUBLE
};

enum
{
	BEGIN,
	MIDDLE,
	END
};

class BaseType
{
protected:
	const std::string	_literal;
	int					_precise;
	bool				_special;
	int					_value;
	double				_double_value;
	float				_float_value;
	int					_type;
public:
	BaseType(std::string literal);
	BaseType(const BaseType& to_copy);
	~BaseType();
	bool			bad_character(char c, int pos);
	std::string		getType() const;
	bool			getSpecial() const;
	bool			getDotFlag() const;
	int				getValue() const;
	int				getPrecise() const;
	double			getDoubleValue() const;
	float			getFloatValue() const;
	std::string		getLiteral() const;
	class WrongInputException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class ImpossibleException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	BaseType& operator=(const BaseType& to_assign);
};

#endif