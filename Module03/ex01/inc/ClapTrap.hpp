/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:12:54 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/04 15:06:32 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>

# define BOLD	"\033[1m"
# define RED	"\033[31m"
# define GREEN 	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"	
# define OFF	"\033[0m"

class ClapTrap
{
	protected:
		std::string	name;
		int			hit_points;
		int			energy_points;
		int			attack_damage;
		
	public:		
		ClapTrap();
		ClapTrap(std::string init_name);
		ClapTrap(const ClapTrap &original);
		ClapTrap&	operator=(const ClapTrap &original);
		~ClapTrap();
		
		void		Attack(const std::string& target);
		void		TakeDamage(unsigned int amount);
		void		BeRepaired(unsigned int amount);

		int			getAttackDamage();
		void		setAttackDamage(int amount);
		bool		CheckIfResourcesAvailable(std::string message);
		std::string GetPointOrPoints(int amount);
};

#endif