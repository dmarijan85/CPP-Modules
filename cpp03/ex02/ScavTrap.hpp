#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class	ScavTrap : public ClapTrap
{
private:
	static const int hp = 100;
    static const int energy = 50;
    static const int atk = 20;
public:
	//constructors and destructors :3
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &cpy);
	~ScavTrap(void);

	//overloads
	ScavTrap & operator = (const ScavTrap &src);
	
	//member functions
	void	guardGate();
};

#endif
