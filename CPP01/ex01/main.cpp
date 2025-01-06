/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:14:24 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/06 17:26:20 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	i;
	Zombie	*horde;
	Zombie 	zombrained("Pol");
	Zombie 	zombotwo("Zombman");

	zombrained.announce();
	randomChump("Chungus");
	zombotwo.announce();

	horde = zombieHorde(5, "MORON");
	for (i=0; i < 5; i++)
	{
		std::cout << i << std::endl;
		horde[i].announce();
	}
	delete[] horde;
	std::cout << std::endl;

	return (0);
}

/*
int main(void)
{
	Zombie zombrained("Ted");
	Zombie zombotwo("Fred");
	Zombie zombotree("Tree");
	Zombie human("Iggy");
	Zombie zombmaster("Zombmaster");

	zombrained.announce();
	zombotwo.announce();
	zombotree.announce();
	human.announce();
	zombmaster.announce();

	std::cout << std::endl;

	return (0);
}*/
