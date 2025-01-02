/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:00:06 by dmarijan          #+#    #+#             */
/*   Updated: 2024/12/30 17:02:55 by dmarijan         ###   ########.fr       */
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
		Contact	*getPhonebook(void);
		void	addtolist(Contact newContact);
		int		getlen(void);
		
};

#endif
