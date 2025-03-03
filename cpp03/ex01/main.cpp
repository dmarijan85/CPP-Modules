#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap scavTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << "Name: " << scavTrapDefault.getName() << std::endl;
    std::cout << "Hit Points: " << scavTrapDefault.getHp() << std::endl;
    std::cout << "Energy Points: " << scavTrapDefault.getEnergy() << std::endl;
    std::cout << "Attack Damage: " << scavTrapDefault.getAtk() << std::endl;
    scavTrapDefault.attack("DefaultTarget");  // Testing attack member function

    // Test Parameterized Constructor
    ScavTrap customScavTrap("CustomScavTrap");
    std::cout << "Parameterized Constructor Test:\n";
    std::cout << "Name: " << customScavTrap.getName() << std::endl;
    std::cout << "Hit Points: " << customScavTrap.getHp() << std::endl;
    std::cout << "Energy Points: " << customScavTrap.getEnergy() << std::endl;
    std::cout << "Attack Damage: " << customScavTrap.getAtk() << std::endl;
    customScavTrap.attack("CustomTarget");

    // Test guardGate member function
    std::cout << "Calling guardGate:\n";
    customScavTrap.guardGate();
    std::cout << "=========================\n";

	return (42);
}
