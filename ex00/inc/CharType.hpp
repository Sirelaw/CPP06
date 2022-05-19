#ifndef CHARTYPE_HPP
#define CHARTYPE_HPP

#include <iostream>
#include <string>
#include "BaseType.hpp"

class CharType : public BaseType
{
private:

public:
	CharType(std::string literal);
	CharType(const CharType& to_copy);
	~CharType();
	class NonDisplayableException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	CharType& operator=(const CharType& to_assign);
};

#endif
