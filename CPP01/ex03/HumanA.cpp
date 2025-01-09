/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:45:16 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/09 13:23:52 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &wep ) : wep(wep), name(name)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void		HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->wep.getType() << std::endl;
}
