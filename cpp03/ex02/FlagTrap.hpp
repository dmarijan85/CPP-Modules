#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class	FlagTrap : public ClapTrap
{
private:
	static const int hp = 100;
    static const int energy = 100;
    static const int atk = 30;
public:
	//constructors and destructors :3
	FlagTrap(void);
	FlagTrap(std::string name);
	FlagTrap(const FlagTrap &cpy);
	~FlagTrap(void);

	//overloads
	FlagTrap & operator = (const FlagTrap &src);
	
	//member functions
	void	highFivesGuys(void);
};

#endif
