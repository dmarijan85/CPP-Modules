/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:11:04 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/04 15:31:45 by dmarijan         ###   ########.fr       */
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
