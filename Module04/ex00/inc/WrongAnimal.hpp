/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:01:24 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/11 10:42:45 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Animal.hpp"

class WrongAnimal
{
	protected:
		std::string type;
		
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& src);
		virtual ~WrongAnimal(void);
		WrongAnimal& operator=(const WrongAnimal& rhs);

		std::string		getType(void) const;
		void			MakeSound(void) const;
};

#endif