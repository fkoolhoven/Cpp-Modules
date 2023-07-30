/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:52:03 by felicia           #+#    #+#             */
/*   Updated: 2023/07/30 15:54:50 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int					fixed_point_number;
		static const int	fractional_bits = 8;
	public:
		Fixed(); // default constructor
		Fixed(const int int_number);
		Fixed(const float float_number);
		~Fixed(); // destructor
		Fixed(const Fixed& original); // copy constructor
		Fixed& 	operator=(const Fixed& original); // copy assignment operator
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
};


// • An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream & operator<<(std::ostream &o, Fixed const &instance);




