/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:52:30 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/11 14:40:01 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

int		ihateerrors(int argc, char **argv)
{
	std::ifstream	file;
	std::ofstream	file2;

	if (argc != 4 )
	{
		std::cout << "Loser parameters! Should be: './loser filename str1 str2'" << std::endl;
		return (1);
	}
	if (!(argv[2]) || !(argv[3]) || !(argv[2][0]) || !(argv[3][0]))
	{
		std::cout << "We don't allow empty strings in this household. Please reconsider." << std::endl;
		return (1);
	}
	file.open(argv[1], std::ifstream::in);
	if (!(file.is_open()))
	{
		std::cout << "File " << argv[1] << \
		" doesn't have a low taper fade (doesn't exist? / check perms)." << std::endl;
		file.close();
		return (1);
	}
	file.close();
	
	std::string		outfile = argv[1];
	outfile += ".replace";
	
	file2.open(outfile.c_str(), std::ofstream::out);
	if (!(file2.is_open()))
	{
		std::cout << "File " << argv[1] << \
		" doesn't have a low taper fade (doesn't exist? / check perms)." << std::endl;
		file2.close();
		return (1);
	}
	return (0);
}

char	lastletter(char	*str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (str[i-1]);
}

int		ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int		wordmatches(const char *baguette, char *str)
{
	int	i = 0;

	while (baguette[i] == str[i])
		i++;
	if (i == ft_strlen(str) || i-1 == ft_strlen(str))
		return (1);
	return (0);
}

void	loserfunction(char **argv)
{
	std::string		baguette;
	std::string		part1 = "";
	std::string		part2 = "";
	std::string		temp = "";
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		outname = argv[1];
	int				i;
	
	outname += ".replace";
	infile.open(argv[1], std::ifstream::in);
	outfile.open(outname.c_str(), std::ofstream::out);
	while (std::getline(infile, baguette))
	{
		part1 = "";
		part1.append(baguette);
		part2 = "";
		for (i=0;part1[i];i++)
		{
			if (wordmatches(part1.c_str() + i, argv[2]))
			{
				temp = part1.substr(0, i);
				part2 = part1.substr(i + ft_strlen(argv[2]), baguette.length());
				part1 = "";
				part1.append(temp);
				part1.append(argv[3]);
				part1.append(part2);
			}
		}
		if (part1[0])
			outfile << part1 << std::endl;
		else
			outfile << baguette << std::endl;
	}
	infile.close();
	outfile.close();
}

int		main(int argc, char **argv)
{
	if (!ihateerrors(argc, argv))
	{
		loserfunction(argv);
		return (0);
	}
	return (1);
}
