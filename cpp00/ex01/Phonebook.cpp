/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:43:54 by dmarijan          #+#    #+#             */
/*   Updated: 2024/12/30 17:15:04 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	len = 0;
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void	Phonebook::addtolist(Contact newContact)
{
	static int	i = 0;

	if (i == 8)
		i = 0;
	book[i] = newContact;
	book[i].setindex(i+1);
	i++;
	if (len != 8)
		len++;
}

Contact *Phonebook::getPhonebook(void)
{ 
	return (book); 
}

int	Phonebook::getlen(void)
{ 
	return (len); 
}
