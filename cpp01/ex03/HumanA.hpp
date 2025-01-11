/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:37:27 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/09 13:21:13 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon		&wep;
		std::string	name;
	public:
		HumanA(std::string name, Weapon &wep);
		~HumanA();
		void		attack(void);
};

#endif
