/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:32:12 by dmarijan          #+#    #+#             */
/*   Updated: 2024/12/21 17:36:54 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	size_t	i;
	int		j = 1;

	if (argc == 1)
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE * " << std::endl;
	else
	{
		while (argv[j])
		{
			for (i=0; i < strlen(argv[j]); i++)
				std::cout << argv[j][i];
			std::cout << " ";
			j++;
		}
		std::cout << std::endl;
	}
	return (0);
}
