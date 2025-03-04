#include "FlagTrap.hpp"
#include "ClapTrap.hpp"

FlagTrap::FlagTrap(void) : ClapTrap("Default", FlagTrap::hp, FlagTrap::energy, FlagTrap::atk) 
{
	std::cout << "Flag Default constructor called" << std::endl;
	return ;
}

FlagTrap::FlagTrap(const FlagTrap& src) : ClapTrap(src)
{
    std::cout << "FlagTrap " << this->getName() << " copy is born!" << std::endl;
    return ;
}

FlagTrap::~FlagTrap(void)
{
    std::cout << "FlagTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

FlagTrap& FlagTrap::operator=(const FlagTrap& rhs)
{
    std::cout << "FlagTrap " << this->getName() << " assignation is born!" << std::endl;
    this->setName(rhs.getName());
    this->setHp(rhs.getHp());
	this->setEnergy(rhs.getEnergy());
    this->setAtk(rhs.getAtk());
    return *this;
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name, FlagTrap::hp, FlagTrap::energy, FlagTrap::atk)
{
	std::cout << "FlagTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

void FlagTrap::highFivesGuys(void)
{
    std::cout << "FlagTrap " << this->getName() << " is straight up High Fivin' it rn!" << std::endl;
    return ;
}
