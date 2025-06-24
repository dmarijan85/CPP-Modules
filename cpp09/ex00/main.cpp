#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
    system("clear");
	if (ac != 2)
	{
		std::cout << "You must pass a file." << std::endl << "FORMAT: ./btc file" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc;
		//btc.execute(av[1]);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
