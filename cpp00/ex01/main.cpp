/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:38:27 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/02 14:03:27 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>

#include "Phonebook.hpp"
#include "Contact.hpp"

//add
static bool ft_isspace(char ch)
{
    return std::isspace(static_cast<unsigned char>(ch));
}

//checks whether the inputted string is all spaces / tabs whatever and returns 
//true or false accordingly.
static bool	ft_legaliser(std::string input)
{
	int	i;

	for (i=0; input[i]; i++)
		if (!ft_isspace(input[i]))
			return (true);
	std::cout << "Field cant be empty!!!" << std::endl;
	return (false);
}

static void	ft_addition(Phonebook *Pbook)
{
	std::string	fname;
	std::string	lname;
	std::string	nname;
	std::string	nbr;
	std::string	secret;

	std::cout << std::endl;
	do
	{
		std::cout << "Introduce the first name: " << std::endl;
		if (std::getline(std::cin, fname).rdstate() != 0)
			exit (1);
	} while (!ft_legaliser(fname));
	do
	{
		std::cout << "Introduce the last name: " << std::endl;
		if (std::getline(std::cin, lname).rdstate() != 0)
			exit (1);
	} while (!ft_legaliser(lname));
	do
	{
		std::cout << "Introduce the nickname: " << std::endl;
		if (std::getline(std::cin, nname).rdstate() != 0)
			exit (1);
	} while (!ft_legaliser(nname));
	do
	{
		std::cout << "Introduce the phone number: " << std::endl;
		if (std::getline(std::cin, nbr).rdstate() != 0)
			exit (1);
	} while (!ft_legaliser(nbr));
	do
	{
		std::cout << "Introduce the darkest secret: " << std::endl;
		if (std::getline(std::cin, secret).rdstate() != 0)
			exit (1);
	} while (!ft_legaliser(secret));
	Contact	newContact(fname, lname, nname, nbr, secret);
	(*Pbook).addtolist(newContact);
}

//search

//cuts the string if its longer than 9 characters and replaces at the tenth character
//with a "."
static std::string check_len(std::string str)
{
	std::string tmp = "          ";
	int j = str.length();

	if (j == 10)
		return (str);
	else if (j < 10)
	{
		tmp = tmp.substr(0, 10-j);
		tmp.append(str);
		return (tmp);
	}
	tmp = str.substr(0,9);
	tmp.append(".");
	return (tmp);
}


static void print_data(Contact contact)
{
	std::cout << "First Name:		" << contact.getfName() << std::endl;
	std::cout << "Last Name:		" << contact.getlName() << std::endl;
	std::cout << "Nick Name:		" << contact.getnName() << std::endl;
	std::cout << "Phone Number:		" << contact.getNbr() << std::endl;
	std::cout << "Darkest Secret:		" << contact.getSecret() << std::endl;
}

//actual search function lol
static void	ft_fbi(Phonebook *Pbook)
{
	int i = 0;
	int j = 1;
	int c = 0;
	std::string	input = "";
	Contact	*temp = (*Pbook).getPhonebook();

	if ((*Pbook).getlen() == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	std::cout << " Index    | F.Name   | L.Name   | Nickname " << std::endl;
	//loops contact list and prints all the info
	while (i < (*Pbook).getlen())
	{
		c = 0;
		while (j == ((*Pbook).getPhonebook())[c].getid())
		{
			std::cout << "         " << temp[c].getid() << "|";
			std::cout << check_len(temp[c].getfName()) << "|";
			std::cout << check_len(temp[c].getlName()) << "|";
			std::cout << check_len(temp[c].getnName()) << std::endl;
			j++;
			c++;
		}
		i++;
	}
	std::cout << std::endl << "Enter an index to display info, or 0 to go back." << std::endl;
	do
	{
		if (std::getline(std::cin, input).rdstate() != 0)
			exit (1);
		if (atoi(input.c_str()) < 0 || atoi(input.c_str()) > Pbook->getlen())
			std::cout << "Index is out of range, try again." << std::endl; 
	} while (atoi(input.c_str()) < 0 || atoi(input.c_str()) > Pbook->getlen());
	if (atoi(input.c_str()) == 0)
		return ;
	else 
		print_data(((*Pbook).getPhonebook())[atoi(input.c_str())-1]);
}


//menu and main

//clears screen, prints the selection choices + small description, and then
//waits for user input, grabs it and converts from string to constant char * with
//c_str(). returns a different int for each operation, -1 in case of no match
static int	printmenu(void)
{
	std::string	input;

	std::cout << std::endl;
	std::cout << "ADD:    save a new contact." << std::endl;
	std::cout << "SEARCH: display a specific contact." << std::endl;
	std::cout << "EXIT:   quit the Phonebook :(" << std::endl;

	std::cout << "Type the operation you wish to perform (ADD/SEARCH/EXIT): ";
	if (std::getline(std::cin, input).rdstate() != 0)
			exit (1);
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
			std::cout << std::endl << "Wrong command, are you sure you typed it correctly?" << std::endl;
		else if (op == 1)
			ft_addition(&Pbook);
		else if (op == 2)
			ft_fbi(&Pbook);
	} while (op != 3);
	std::cout << "Exiting Phonebook..." << std::endl << std::endl;
	return (0);
}
