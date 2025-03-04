#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default", ScavTrap::hp, ScavTrap::energy, ScavTrap::atk) 
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
    std::cout << "ScavTrap " << this->getName() << " copy is born!" << std::endl;
    return ;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    std::cout << "ScavTrap " << this->getName() << " assignation is born!" << std::endl;
    this->setName(rhs.getName());
    this->setHp(rhs.getHp());
	this->setEnergy(rhs.getEnergy());
    this->setAtk(rhs.getAtk());
    return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, ScavTrap::hp, ScavTrap::energy, ScavTrap::atk)
{
	std::cout << "ScavTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->getName() << " is straight up Gate Keepin' it rn!" << std::endl;
    return ;
}
