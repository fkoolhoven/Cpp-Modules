/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:14:13 by felicia           #+#    #+#             */
/*   Updated: 2023/11/23 17:59:52 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "HumanA.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		HumanB(std::string new_name);
		~HumanB(void);
		void	setWeapon(Weapon &new_weapon);
		void	attack(void);
};

#endif