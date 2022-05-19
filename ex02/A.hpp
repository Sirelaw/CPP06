#ifndef A_HPP
#define A_HPP

#include <iostream>
#include <string>
#include "Base.hpp"

class A : public Base
{
private:

public:
	A();
	A(const A& to_copy);
	~A();
	A& operator=(const A& to_assign);
};

#endif


