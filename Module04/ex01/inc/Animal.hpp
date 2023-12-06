/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:00:59 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/06 15:29:48 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <cstdlib>

# define RED	"\033[31m"
# define GREEN 	"\033[32m"
# define YELLOW "\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

class Animal
{
	protected:
		std::string type;
		
	public:
		Animal(void);
		Animal(const Animal& src);
		virtual ~Animal(void);
		Animal& operator=(const Animal& src);

		std::string		getType(void) const;
		virtual void	MakeSound(void) const;
};

#endif