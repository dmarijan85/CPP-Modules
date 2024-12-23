/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:38:27 by dmarijan          #+#    #+#             */
/*   Updated: 2024/12/23 16:45:08 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>
#include <cstring>

#include "Phonebook.hpp"
#include "Contact.hpp"

//clears screen, prints the selection choices + small description, and then
//waits for user input, grabs it and converts from string to constant char * with
//c_str(). returns a different int for each operation, -1 in case of no match
int	printmenu(void)
{
	std::string	input;

	std::cout << "\033[2JADD: save a new contact." << std::endl;
	std::cout << "SEARCH: display a specific contact." << std::endl;
	std::cout << "EXIT: quit the Phonebook :(" << std::endl;

	std::cout << "Type the operation you wish to perform (ADD/SEARCH/EXIT): ";
	std::cin >> input;
	if (!strcmp(input.c_str(), "ADD"))
		return (1);
	else if (!strcmp(input.c_str(), "SEARCH"))
		return (2);
	else if (!strcmp(input.c_str(), "EXIT"))
		return (3);
	return (-1);
}

int		main(void)
{
	Phonebook	Pbook;
	int			op;
	
	//do while loop that continues indefinitely until EXIT command is typed in
	do
	{
		op = printmenu();
		//little error message because im nice like that
		if (op == -1)
			std::cout << "Wrong command, are you sure you typed it correctly?" << std::endl;
	} while (op != 3);

	return (0);
}
