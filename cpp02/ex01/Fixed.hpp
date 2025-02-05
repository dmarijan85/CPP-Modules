/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:07:28 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/05 13:54:36 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed & src);
		Fixed(const int nbr);
		Fixed(const float nbr);
		~Fixed(void);
		Fixed & operator = (const Fixed & rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					pValue;
		static const int	fBits = 8;
};

std::ostream & operator << (std::ostream &out, const Fixed &fixed);

#endif
