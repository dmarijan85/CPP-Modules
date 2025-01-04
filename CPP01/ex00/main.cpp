/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:14:24 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/04 15:33:02 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie zombrained("Pol");
	Zombie zombotwo("Zombman");

	zombrained.announce();
	randomChump("Chungus");
	zombotwo.announce();	

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
