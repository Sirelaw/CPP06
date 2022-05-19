#ifndef C_HPP
#define C_HPP

#include <iostream>
#include <string>
#include "Base.hpp"

class C : public Base
{
private:

public:
	C();
	C(const C& to_copy);
	~C();
	C& operator=(const C& to_assign);
};

#endif