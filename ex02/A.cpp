#include "A.hpp"

A::A()
{
	
}

A::A(const A& to_copy)
{
	(void) to_copy;
}

A::~A()
{
	
}

A& A::operator=(const A& to_assign)
{
	if (this != &to_assign)
	{
		
	}
	return (*this);
}