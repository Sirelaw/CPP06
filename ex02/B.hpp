#ifndef B_HPP
#define B_HPP

#include <iostream>
#include <string>
#include "Base.hpp"

class B : public Base
{
private:

public:
	B();
	B(const B& to_copy);
	~B();
	B& operator=(const B& to_assign);
};

#endif