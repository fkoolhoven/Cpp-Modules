/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:55:41 by felicia           #+#    #+#             */
/*   Updated: 2023/12/04 16:54:16 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>

class ScavTrap : public ClapTrap
{
	private:
		bool	guarding_gate;

	public:
		ScavTrap(); 
		ScavTrap(std::string init_name); 
		ScavTrap(const ScavTrap &original); 
		ScavTrap&	operator=(const ScavTrap &original);
		~ScavTrap();
		
		void	Attack(const std::string& target);
		void	GuardGate();
};

#endif