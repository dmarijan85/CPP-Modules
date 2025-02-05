/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:19:13 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/05 15:15:59 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->pValue = 0;
	return ;
}

Fixed::Fixed(const Fixed & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(const Fixed & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->pValue = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->pValue;
}

void	Fixed::setRawBits(int const nbr)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->pValue = nbr;
	return ;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->pValue = value << fBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->pValue = roundf(value * (1 << fBits));
}

int		Fixed::toInt(void) const
{
	return ((this->pValue) >> fBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->pValue) / (1 << fBits));
}

std::ostream & operator << (std::ostream &outp, const Fixed &fixed)
{
	outp << fixed.toFloat();
	return outp;
}
