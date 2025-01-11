/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:42:54 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/06 17:54:08 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string	brian = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brian;
	std::string	&stringREF = brian;

	std::cout << "The memory address of the string variable: " << &brian << std::endl;
	std::cout << "The memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address of stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string variable: " << brian << std::endl;
	std::cout << "The value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value of stringREF: " << stringREF << std::endl;

	return (0);
}
