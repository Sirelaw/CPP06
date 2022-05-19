#include <unistd.h>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int			random;

	srand(time(NULL));
	random = rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new C);
	else
		return (new B);
}

void	identify(Base *p)
{
	{
		A* temp = dynamic_cast<A *> (p);
		if (temp)
			std::cout << "Randomly generated pointer: A" << std::endl;
	}
	{
		B* temp = dynamic_cast<B *> (p);
		if (temp)
			std::cout << "Randomly generated pointer: B" << std::endl;
	}
	{
		C* temp = dynamic_cast<C *> (p);
		if (temp)
			std::cout << "Randomly generated pointer: C" << std::endl;
	}
	delete p;
}

void	identify(Base &p)
{
	try
	{
		A temp = dynamic_cast<A&> (p);
		std::cout << "Randomly generated reference: A" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		B temp = dynamic_cast<B&> (p);
		std::cout << "Randomly generated reference: B" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		C temp = dynamic_cast<C&> (p);
		std::cout << "Randomly generated reference: C" << std::endl;
	}
	catch(const std::exception& e){}
	delete &p;
}

int main()
{
	identify((generate()));
	usleep(500000);
	identify(*(generate()));
	return 0;
}