/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:55:41 by felicia           #+#    #+#             */
/*   Updated: 2023/08/15 19:07:34 by felicia          ###   ########.fr       */
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
		ScavTrap(std::string init_name);
		~ScavTrap();
	
		void	attack(const std::string& target);
		void	guardGate();
};

#endif
