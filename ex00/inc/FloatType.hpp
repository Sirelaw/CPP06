#ifndef FLOATTYPE_HPP
#define FLOATTYPE_HPP

#include <iostream>
#include <string>
#include "BaseType.hpp"

class FloatType : public BaseType
{
private:
	
public:
	FloatType(std::string literal);
	FloatType(const FloatType& to_copy);
	~FloatType();
	FloatType& operator=(const FloatType& to_assign);
};

#endif