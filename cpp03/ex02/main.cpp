#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int	main(void)
{
	FlagTrap flagTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << "Name: " << flagTrapDefault.getName() << std::endl;
    std::cout << "Hit Points: " << flagTrapDefault.getHp() << std::endl;
    std::cout << "Energy Points: " << flagTrapDefault.getEnergy() << std::endl;
    std::cout << "Attack Damage: " << flagTrapDefault.getAtk() << std::endl;
    flagTrapDefault.attack("DefaultTarget");  // Testing attack member function

    FlagTrap customFlagTrap("CustomScavTrap");
    std::cout << "Parameterized Constructor Test:\n";
    std::cout << "Name: " << customFlagTrap.getName() << std::endl;
    std::cout << "Hit Points: " << customFlagTrap.getHp() << std::endl;
    std::cout << "Energy Points: " << customFlagTrap.getEnergy() << std::endl;
    std::cout << "Attack Damage: " << customFlagTrap.getAtk() << std::endl;
    customFlagTrap.attack("CustomTarget");

    // Test guardGate member function
    std::cout << "Calling highFivesGuys:\n";
    customFlagTrap.highFivesGuys();
    std::cout << "=========================\n";

	return (42);
}
