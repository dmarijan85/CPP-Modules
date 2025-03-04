#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class	FragTrap : virtual public ClapTrap
{
private:
    static const int energy = 100;
protected:
	static const int hp = 100;
    static const int atk = 30;
public:
	//constructors and destructors :3
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &cpy);
	~FragTrap(void);

	//overloads
	FragTrap & operator = (const FragTrap &src);
	
	//member functions
	void	highFivesGuys(void);
};

#endif
