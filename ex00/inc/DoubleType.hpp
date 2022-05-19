#ifndef DOUBLETYPE_HPP
#define DOUBLETYPE_HPP

#include <iostream>
#include <string>
#include "BaseType.hpp"

class DoubleType : public BaseType
{
private:
	
public:
	DoubleType(std::string literal);
	DoubleType(const DoubleType& to_copy);
	~DoubleType();
	DoubleType& operator=(const DoubleType& to_assign);
};

#endif