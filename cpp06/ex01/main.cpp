#include "Serializer.hpp"

int	main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*ptr;

	data.name = "FUNNY";
	std::cout << "Data &: " << &data << "\n";
	raw = Serializer::serialize(&data);
	std::cout << "RAW &: " << &raw << "\n";
	ptr = Serializer::deserialize(raw);
	std::cout << "PTR &: " << &ptr << "\n";
	if (ptr == &data)
		std::cout << "Data Name: " << ptr->name << "\n";
	return (0);
}
