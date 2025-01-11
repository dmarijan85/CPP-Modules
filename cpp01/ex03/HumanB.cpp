/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:45:16 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/09 13:36:50 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : wep(NULL), name(name) 
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void		HumanB::attack(void)
{
	if (this->wep)
		std::cout << this->name << " attacks with their " << wep->getType() << std::endl;
	else
		std::cout << this->name << " is unarmed. Can't attack!" << std::endl;
}

void		HumanB::setWeapon(Weapon &weapon)
{
	std::cout << this->name << " grabbed a " << weapon.getType() << "!" << std::endl;
	this->wep = &weapon;
}
