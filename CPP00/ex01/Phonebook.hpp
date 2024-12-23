/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:00:06 by dmarijan          #+#    #+#             */
/*   Updated: 2024/12/23 16:34:25 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	Phonebook
{
	private:
		Contact	book[8];
		int		len;
	public:
		Phonebook();
		~Phonebook();
		void	addContact(Contact newContact);
		Contact	*getPhonebook(void);

		
};

#endif
