/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:03:44 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/11 15:42:48 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		Cat(void);
		Cat(const Cat& src);
		~Cat(void);
		Cat& operator=(const Cat& src);

		Brain* getBrain(void) const;
		void MakeSound(void) const;
};

#endif