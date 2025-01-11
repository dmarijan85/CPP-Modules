/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:54:17 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/09 13:35:15 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = "";
}

Weapon::~Weapon()
{
	return ;
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

std::string	&Weapon::getType(void)
{
	return (this->type);
}

void		Weapon::setType(std::string str)
{
	this->type = str;
}
