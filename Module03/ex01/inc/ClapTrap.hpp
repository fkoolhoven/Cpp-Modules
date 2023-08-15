/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:12:54 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/08/15 19:14:52 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

# define RED	"\033[31m"
# define GREEN 	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"	
# define OFF	"\033[0m"

class ClapTrap
{
	protected:
		std::string	Name;
		int			HitPoints;
		int			EnergyPoints;
		int			AttackDamage;
	
	public:		
		ClapTrap(); // default constructor
		ClapTrap(std::string init_name); // name constructor
		ClapTrap(const ClapTrap &original); // copy constructor
		ClapTrap&	operator=(const ClapTrap &original); // copy assignment operator
		~ClapTrap(); // default destructor

		int		getAttackDamage(void) { return (AttackDamage); };
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	get_point_or_points(int amount);
};

#endif
