/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:04:05 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/11 15:54:06 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *brain;
		
	public:
		Dog(void);
		Dog(const Dog& src);
		~Dog(void);
		Dog& operator=(const Dog& src);

		Brain* getBrain(void) const;
		void MakeSound(void) const;
		virtual void PureVirtualFunction(void) const;
};

#endif