/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:52:03 by felicia           #+#    #+#             */
/*   Updated: 2023/07/29 14:22:50 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int					number_value;
		static const int	raw = 8;
	public:
		Fixed(); // default constructor
		~Fixed(); // destructor
		Fixed(const Fixed& original); // copy constructor
		Fixed& 	operator=(const Fixed& original); // copy assignment operator
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
