#ifndef INTTYPE_HPP
#define INTTYPE_HPP

#include <iostream>
#include <string>
#include "BaseType.hpp"

class IntType : public BaseType
{
private:
	
public:
	IntType(std::string literal);
	IntType(const IntType& to_copy);
	~IntType();
	IntType& operator=(const IntType& to_assign);
};

#endif