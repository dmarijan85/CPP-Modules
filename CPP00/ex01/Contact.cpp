/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:34:56 by dmarijan          #+#    #+#             */
/*   Updated: 2024/12/23 16:39:24 by dmarijan         ###   ########.fr       */
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
	return ;
}

Contact::Contact(void)
{
	firstName = "";
	lastName = "";
	nickName = "";
	nbr = "";
	secret = "";
	return ;
}

Contact::~Contact(void)
{ 
	return ; 
}
