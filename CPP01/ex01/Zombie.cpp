/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:07:59 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/11 14:34:50 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie	*zomber = new Zombie(name);

	return (zomber);
}

void	randomChump(std::string name)
{
	Zombie zombaba(name);

	zombaba.announce();
}

void	Zombie::setName(std::string name)
{
	this->name = name;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	name = "";
	return ;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->name << ": DeeaaaaaaadddzzzZ..." << std::endl;
	return ;
}
