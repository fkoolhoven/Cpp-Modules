/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:52:03 by felicia           #+#    #+#             */
/*   Updated: 2023/11/29 15:27:26 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class Fixed
{
	private:
		int					fixed_point_number;
		static const int	fractional_bits = 8;
		
	public:
		Fixed();
		Fixed(const int int_number);
		Fixed(const float float_number);
		Fixed(const Fixed& original);
		Fixed& operator=(const Fixed& original);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&		min(Fixed& number1, Fixed& number2);
		static const Fixed&	min(const Fixed& number1, const Fixed& number2);
		static Fixed&		max(Fixed& number1, Fixed& number2);
		static const Fixed&	max(const Fixed& number1, const Fixed& number2);
		
		float	operator+(const Fixed& instance) const;
		float	operator-(const Fixed& instance) const;
		float	operator*(const Fixed& instance) const;
		float	operator/(const Fixed& instance) const;
	
		bool	operator>(const Fixed& instance) const; 
		bool	operator<(const Fixed& instance) const;
		bool	operator>=(const Fixed& instance) const;
		bool	operator<=(const Fixed& instance) const;
		bool	operator==(const Fixed& instance) const;
		bool	operator!=(const Fixed& instance) const;

		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
};

std::ostream& operator<<(std::ostream& o, Fixed const& instance);

#endif