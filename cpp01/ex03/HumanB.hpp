/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:37:27 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/09 13:30:25 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*wep;
		std::string	name;
	public:
		HumanB(std::string name);
		~HumanB();
		void		attack(void);
		void		setWeapon(Weapon &wep);
};

#endif
