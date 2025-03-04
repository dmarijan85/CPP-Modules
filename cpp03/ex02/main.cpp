#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap fragTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << "Name: " << fragTrapDefault.getName() << std::endl;
    std::cout << "Hit Points: " << fragTrapDefault.getHp() << std::endl;
    std::cout << "Energy Points: " << fragTrapDefault.getEnergy() << std::endl;
    std::cout << "Attack Damage: " << fragTrapDefault.getAtk() << std::endl;
    fragTrapDefault.attack("DefaultTarget");  // Testing attack member function

    FragTrap customFragTrap("CustomScavTrap");
    std::cout << "Parameterized Constructor Test:\n";
    std::cout << "Name: " << customFragTrap.getName() << std::endl;
    std::cout << "Hit Points: " << customFragTrap.getHp() << std::endl;
    std::cout << "Energy Points: " << customFragTrap.getEnergy() << std::endl;
    std::cout << "Attack Damage: " << customFragTrap.getAtk() << std::endl;
    customFragTrap.attack("CustomTarget");

    // Test guardGate member function
    std::cout << "Calling highFivesGuys:\n";
    customFragTrap.highFivesGuys();
    std::cout << "=========================\n";

	return (42);
}
