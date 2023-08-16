/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:55:41 by felicia           #+#    #+#             */
/*   Updated: 2023/08/16 17:37:00 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>

class ScavTrap : public ClapTrap
{
	private:

	public:
		ScavTrap(); // default constructor
		ScavTrap(std::string init_name); // name constructor
		ScavTrap(const ScavTrap &original); // copy constructor
		ScavTrap&	operator=(const ScavTrap &original); // copy assignment operator
		~ScavTrap(); // destructor
	
		
	
		void	attack(const std::string& target);
		void	guardGate();
};

#endif
