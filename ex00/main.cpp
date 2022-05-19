#include <iostream>
#include <iomanip>
#include <sstream>
#include "inc/BaseType.hpp"
#include "inc/CharType.hpp"
#include "inc/IntType.hpp"
#include "inc/DoubleType.hpp"
#include "inc/FloatType.hpp"

int main (int argc, char **argv) 
{
	if (argc != 2)
		return (1);
	try
	{
		BaseType	input(argv[1]);
	
		std::cout << "type: " << input.getType() << std::endl;
		try
		{
			CharType	input(argv[1]);

			std::cout << "char:	'" << static_cast <char> (input.getValue()) << "'" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "char:	" << e.what() << std::endl;
		}
		try
		{
			IntType	input(argv[1]);

			std::cout << "int:	" << static_cast <int> (input.getValue()) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "int:	" << e.what() << std::endl;
		}
		try
		{
			FloatType	input(argv[1]);
			
			if (input.getSpecial())
				std::cout << "float:	" << input.getLiteral() << 'f' << std::endl;
			else
				std::cout << "float:	" << std::fixed << std::setprecision(input.getPrecise()) 
				<< static_cast <float> (input.getFloatValue()) << 'f' << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cout << "float:	" << e.what() << std::endl;
		}
		try
		{
			DoubleType	input(argv[1]);
			
			if (input.getSpecial())
				std::cout << "double:	" << input.getLiteral() << std::endl;
			else
				std::cout << "double:	" << std::fixed << std::setprecision(input.getPrecise()) 
				<< static_cast <double> (input.getDoubleValue()) << std::endl;


		}
		catch(const std::exception& e)
		{
			std::cout << "double:	" << e.what() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
