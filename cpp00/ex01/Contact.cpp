/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:34:56 by dmarijan          #+#    #+#             */
/*   Updated: 2024/12/30 17:09:10 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string fName, std::string lName, std::string nName, std::string number, std::string secret)
{
	this->firstName = fName;
	this->lastName = lName;
	this->nickName = nName;
	this->nbr = number;
	this->secret = secret;
	i = 0;
	return ;
}

Contact::Contact(void)
{
	firstName = "";
	lastName = "";
	nickName = "";
	nbr = "";
	secret = "";
	i = 0;
	return ;
}

Contact::~Contact(void)
{ 
	return ; 
}

void	Contact::setindex(int index)
{
	i = index;
}

std::string Contact::getfName(void)
{ 
	return (firstName); 
}

std::string Contact::getlName(void)
{ 
	return (lastName); 
}

std::string Contact::getnName(void)
{ 
	return (nickName); 
}

std::string Contact::getNbr(void)
{ 
	return (nbr); 
}

std::string Contact::getSecret(void)
{ 
	return (secret); 
}

int 		Contact::getid(void)
{ 
	return (i); 
}
