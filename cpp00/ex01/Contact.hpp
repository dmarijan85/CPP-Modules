/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:00:06 by dmarijan          #+#    #+#             */
/*   Updated: 2024/12/30 17:08:10 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	nbr;
		std::string	secret;
		int			i;
	public:
		Contact(std::string firstName, std::string lastName, std::string nickName, std::string nbr, std::string secret);
		Contact();
		~Contact();
		std::string	getfName(void);
		std::string	getlName(void);
		std::string	getnName(void);
		std::string	getNbr(void);
		std::string	getSecret(void);
		int			getid(void);
		void		setindex(int index);
};

#endif
