#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class	DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;
public:
	//constructors and destructors :3
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &cpy);
	~DiamondTrap(void);

	//overloads
	DiamondTrap & operator = (const DiamondTrap &src);
	
	int 		getHp(void) const;
    int 		getEnergy(void) const;
    int 		getAtk(void) const;
	std::string	getClapTrapName(void) const;
	//member functions
	void	whoAmI(void);
};

#endif
