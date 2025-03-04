#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default", FragTrap::hp, FragTrap::energy, FragTrap::atk) 
{
	std::cout << "Flag Default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
    std::cout << "FragTrap " << this->getName() << " copy is born!" << std::endl;
    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    std::cout << "FragTrap " << this->getName() << " assignation is born!" << std::endl;
    this->setName(rhs.getName());
    this->setHp(rhs.getHp());
	this->setEnergy(rhs.getEnergy());
    this->setAtk(rhs.getAtk());
    return *this;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, FragTrap::hp, FragTrap::energy, FragTrap::atk)
{
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getName() << " is straight up High Fivin' it rn!" << std::endl;
    return ;
}
