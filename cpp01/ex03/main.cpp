/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:42:52 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/09 13:37:25 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
//modified main
int main()
{
	{
		Weapon club = Weapon("stone brick");
	
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("dagger");
		bob.attack();
	}
	
	{
		Weapon club = Weapon("branch");
	
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
	}
}
*/

//main provided by subject
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
	
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	
	{
		Weapon club = Weapon("crude spiked club");
	
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	
	return 0;
}
