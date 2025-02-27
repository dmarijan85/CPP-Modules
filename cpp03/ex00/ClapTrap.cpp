#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "";
	this->_hp = 10;
	this->_energy = 10;
	this->_atk = 0;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "String constructor called" << std::endl;
	this->_name = name;
	this->_hp = 10;
	this->_energy = 10;
	this->_atk = 0;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	ClapTrap::showHp(void)
{
	std::cout << "Current HP: " << _hp << std::endl;
	return ;
}

void	ClapTrap::showEnergy(void)
{
	std::cout << "Remaining Energy: " << _energy << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_hp <= 0 || _energy <= 0)
		std::cout << "Bruh, ClapTrap " << _name << " cannot attack, hes fucking done for!" << std::endl;
	else
	{
		std::cout << "Woah! ClapTrap " << _name << " just hit " << target << " for an insane amount of " << _atk << " HP!" << std::endl;
		_energy--;
		this->showEnergy();
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Ouch! ClapTrap " << _name << " just got hit for an exorbitant amount of " << amount << " HP!" << std::endl;
	_hp -= amount;
	_energy--;
	this->showHp();
	this->showEnergy();
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0 || _energy <= 0)
		std::cout << "Bruh, ClapTrap " << _name << " cannot repair, hes fucking done for!" << std::endl;
	else
	{
		std::cout << "Damn, ClapTrap " << _name << " is straight up repairing it rn! And by it, well, lets just say, by " << amount << " HP!" << std::endl;
		_hp += amount;
		_energy--;
		this->showHp();
		this->showEnergy();
	}
	return ;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &src)
{
	this->_hp = src._hp;
	this->_name = src._name;
	this->_atk = src._atk;
	this->_energy = src._energy;
	return (*this);
}

std::string	ClapTrap::getName(void)
{
	return (this->_name);
}

void	ClapTrap::setHp(int newhp)
{
	this->_hp = newhp;
}
