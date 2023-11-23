/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:14:21 by felicia           #+#    #+#             */
/*   Updated: 2023/11/23 18:00:01 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;

	public:
		HumanA(std::string new_name, Weapon &new_weapon);
		~HumanA(void);
		void	attack(void);
};

#endif