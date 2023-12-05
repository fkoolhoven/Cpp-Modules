/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:00:59 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 17:09:15 by fkoolhov         ###   ########.fr       */
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

class AAnimal
{
	protected:
		std::string type;
		
	public:
		AAnimal(void);
		AAnimal(const AAnimal& src);
		virtual ~AAnimal(void);
		AAnimal& operator=(const AAnimal& rhs);

		virtual void	MakeSound(void) const;
		std::string		getType(void) const;
		virtual void	PureVirtualFunction(void) const = 0;
};

#endif