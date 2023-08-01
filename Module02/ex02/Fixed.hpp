/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:52:03 by felicia           #+#    #+#             */
/*   Updated: 2023/08/01 12:56:19 by felicia          ###   ########.fr       */
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

		static Fixed&		min(Fixed &number1, Fixed &number2);
		static const Fixed&	min(Fixed const &number1, Fixed const &number2);
		static Fixed&		max(Fixed &number1, Fixed &number2);
		static const Fixed&	max(Fixed const &number1, Fixed const &number2);
		


		int	operator+(Fixed const &instance);
		int	operator-(Fixed const &instance);
		int	operator*(Fixed const &instance);
		int	operator/(Fixed const &instance);
	
		int	operator>(Fixed const &instance);
		int	operator<(Fixed const &instance);
		int	operator>=(Fixed const &instance);
		int	operator<=(Fixed const &instance);
		int	operator==(Fixed const &instance);
		int	operator!=(Fixed const &instance);

		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
};

// • An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream&	operator<<(std::ostream &o, Fixed const &instance);


// • A static member function min that takes as parameters two references on fixed-point
// numbers, and returns a reference to the smallest one.
// • A static member function min that takes as parameters two references to constant
// fixed-point numbers, and returns a reference to the smallest one.
// • A static member function max that takes as parameters two references on fixed-point
// numbers, and returns a reference to the greatest one.
// • A static member function max that takes as parameters two references to constant
// fixed-point numbers, and returns a reference to the greatest one.
