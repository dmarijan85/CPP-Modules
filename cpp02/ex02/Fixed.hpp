/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:07:28 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/06 13:59:05 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
	//constructors and destructors
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed(const int nbr);
		Fixed(const float nbr);
		~Fixed(void);
	//overloaded operators
		Fixed & operator = (const Fixed &rhs);
		bool	operator > (const Fixed &rhs) const;
		bool	operator < (const Fixed &rhs) const;
		bool	operator >= (const Fixed &rhs) const;
		bool	operator <= (const Fixed &rhs) const;
		bool	operator == (const Fixed &rhs) const;
		bool	operator != (const Fixed &rhs) const;
		Fixed	operator + (const Fixed &rhs) const;
		Fixed	operator - (const Fixed &rhs) const;
		Fixed	operator * (const Fixed &rhs) const;
		Fixed	operator / (const Fixed &rhs) const;
	//pre increment
		Fixed & operator ++ ();
		Fixed & operator -- ();
	//post increment
		Fixed	operator ++ (int);
		Fixed	operator -- (int);
	//member functions
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static const Fixed	&min(Fixed &first, Fixed &second);
		static const Fixed	&min(const Fixed &first, const Fixed &second);
		static const Fixed	&max(Fixed &first, Fixed &second);
		static const Fixed	&max(const Fixed &first, const Fixed &second);
	private:
		int					pValue;
		static const int	fBits = 8;
};

std::ostream & operator << (std::ostream &out, const Fixed &fixed);

#endif
