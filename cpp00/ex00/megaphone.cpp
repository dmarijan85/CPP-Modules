/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:32:12 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/03 12:30:34 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>

int main(int argc, char **argv)
{
	size_t	i;
	int		j = 1;

	//custom message si no hay args
	if (argc == 1)
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE * " << std::endl;
	else
	{
		while (argv[j])
		{
			for (i=0; i < strlen(argv[j]); i++)
			{
				//si estamos en un espacio y estamos al principio o final del string o 
				//hay mas espacios a seguir, no imprimimos.
				if (argv[j][i] == ' ' && (i == 0 || i == strlen(argv[j])-1 || argv[j][i+1] == ' '))
					;
				else
					std::cout << (char)(toupper(argv[j][i]));
			}
			//imprimimos el UNICO espacio entre argumentos y chilleamos
			std::cout << " ";
			j++;
		}
		//una unica endline
		std::cout << std::endl;
	}
	return (0);
}
