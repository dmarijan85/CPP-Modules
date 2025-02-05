/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:07:28 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/28 14:51:30 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed & src);
		~Fixed(void);
		Fixed & operator = (const Fixed & rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					pValue;
		static const int	fBits = 8;
};

#endif
