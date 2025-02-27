#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap jerry;
	ClapTrap jim("Jim Carrey");
	ClapTrap chung("chung");
	ClapTrap terry(chung);
	
	jerry = jim;
	std::cout << std::endl;
	terry.attack(jim.getName());
	std::cout << std::endl;
	for (int i = 0; i < 15; i++)
		chung.beRepaired(1);
	std::cout << std::endl;
	jim.setHp(-42);
	jim.attack("the air");
	jim.beRepaired(42);
	std::cout << std::endl;
	return (0);
}
