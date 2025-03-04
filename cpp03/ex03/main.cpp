#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamondTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << "Hit Points: " << diamondTrapDefault.getHp() << std::endl;
    std::cout << "Energy Points: " << diamondTrapDefault.getEnergy() << std::endl;
    std::cout << "Attack Damage: " << diamondTrapDefault.getAtk() << std::endl;
    std::cout << "ClapTrap Name: " << diamondTrapDefault.getClapTrapName() << std::endl;
    diamondTrapDefault.whoAmI();
    diamondTrapDefault.attack("Target");
    std::cout << "=========================\n";

    // Test Copy Constructor
    DiamondTrap diamondTrapCopy(diamondTrapDefault);
    std::cout << "Copy Constructor Test:\n";
    std::cout << "Hit Points: " << diamondTrapCopy.getHp() << std::endl;
    std::cout << "Energy Points: " << diamondTrapCopy.getEnergy() << std::endl;
    std::cout << "Attack Damage: " << diamondTrapCopy.getAtk() << std::endl;
    std::cout << "ClapTrap Name: " << diamondTrapCopy.getClapTrapName() << std::endl;
    diamondTrapCopy.whoAmI();
    diamondTrapCopy.attack("Target");
    std::cout << "=========================\n";

    // Test Assignment Operator
    DiamondTrap diamondTrapAssign;
    diamondTrapAssign = diamondTrapCopy;
    std::cout << "Assign Constructor Test:\n";
    std::cout << "Hit Points: " << diamondTrapAssign.getHp() << std::endl;
    std::cout << "Energy Points: " << diamondTrapAssign.getEnergy() << std::endl;
    std::cout << "Attack Damage: " << diamondTrapAssign.getAtk() << std::endl;
    std::cout << "ClapTrap Name: " << diamondTrapAssign.getClapTrapName() << std::endl;
    diamondTrapAssign.whoAmI();
    diamondTrapAssign.attack("Target");
    std::cout << "=========================\n";

    // Test Parameterized Constructor
    DiamondTrap customDiamond("CustomDiamond");
    std::cout << "Custom Constructor Test:\n";
    std::cout << "Hit Points: " << customDiamond.getHp() << std::endl;
    std::cout << "Energy Points: " << customDiamond.getEnergy() << std::endl;
    std::cout << "Attack Damage: " << customDiamond.getAtk() << std::endl;
    std::cout << "ClapTrap Name: " << customDiamond.getClapTrapName() << std::endl;
    customDiamond.whoAmI();
    customDiamond.attack("Target");
    std::cout << "=========================\n";
}
