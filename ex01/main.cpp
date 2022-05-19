#include <iostream>
#include "Data.hpp"

uintptr_t	serialize(Data* ptr)
{
	uintptr_t	coded;

	coded = reinterpret_cast <uintptr_t> (ptr);
	return (coded);
}

Data*	deserialize(uintptr_t raw)
{
	Data*	decoded;

	decoded = reinterpret_cast <Data *> (raw);
	return (decoded);
}

int	main()
{
	Data*	ptr;
	Data	created;
	Data*	ret_ptr;

	ptr = &created;
	ptr->_num = 2023;
	ptr->_float = 4232322.332333f;
	ptr->_char = 'b';
	ptr->_double = 12359323;
	ret_ptr = deserialize(serialize(ptr));
	std::cout << ret_ptr->_skill << std::endl;
	std::cout << ret_ptr->_num << std::endl;
	std::cout << ret_ptr->_char << std::endl;
	std::cout << ret_ptr->_float << std::endl;
	std::cout << ret_ptr->_double << std::endl;
	return (0);
}