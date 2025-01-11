/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:25:43 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/11 14:28:55 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harloid;

	harloid.complain("DEBUG");
	std::cout << std::endl;
	harloid.complain("INFO");
	std::cout << std::endl;
	harloid.complain("WARNING");
	std::cout << std::endl;
	harloid.complain("ERROR");
	std::cout << std::endl;
	harloid.complain("HARLMODE");
	std::cout << std::endl;
	return (0);
}
