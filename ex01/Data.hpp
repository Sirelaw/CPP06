#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{
private:
public:
	std::string	_skill;
	int			_num;
	float		_float;
	char		_char;
	double		_double;
	Data();
	Data(const Data& to_copy);
	~Data();
	Data& operator=(const Data& to_assign);
};

#endif