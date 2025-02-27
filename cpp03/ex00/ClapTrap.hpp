#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap {
private:
	std::string	_name;
	int			_hp;
	int			_energy;
	int			_atk;
public:
	//constructors and destructors :3
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &cpy);
	~ClapTrap(void);

	//overloads
	ClapTrap & operator = (const ClapTrap &src);
	
	//member functions
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		showHp(void);
	void		showEnergy(void);
	std::string	getName(void);
	void		setHp(int newhp);
};

#endif
