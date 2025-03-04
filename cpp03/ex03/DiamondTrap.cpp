#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name", FragTrap::hp, ScavTrap::energy, FragTrap::atk) 
{
	this->_name = "Default";
	std::cout << "Diamond Default constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	this->_name = src._name;
    std::cout << "DiamondTrap " << this->getName() << " copy is born!" << std::endl;
    return ;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "ScavTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
    std::cout << "ScavTrap " << this->getName() << " assignation is born!" << std::endl;
    this->_name = rhs._name;
    this->setHp(rhs.getHp());
	this->setEnergy(rhs.getEnergy());
    this->setAtk(rhs.getAtk());
    return *this;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", FragTrap::hp, ScavTrap::energy, FragTrap::atk)
{
	std::cout << "ScavTrap " << this->getName() << " is born!" << std::endl;
	this->_name = name;
    return ;
}

int DiamondTrap::getHp(void) const
{
    return FragTrap::getHp();
}

int DiamondTrap::getEnergy(void) const
{
    return ScavTrap::getEnergy();
}

int DiamondTrap::getAtk(void) const 
{
    return FragTrap::getAtk();
}

std::string DiamondTrap::getClapTrapName(void) const
{
    return ClapTrap::getName();
}

void DiamondTrap::whoAmI( void ) {
    std::cout << "I am " << this->_name << " and my ClapTrap name is " << this->getClapTrapName() << std::endl;
}
