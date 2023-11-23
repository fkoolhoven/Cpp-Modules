/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:35 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/11/23 15:17:08 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cstdlib>

// =====MACROS==================================================================

# define BOLD	"\033[1m"
# define RED	"\033[31m"
# define GREEN 	"\033[32m"
# define YELLOW	"\033[33m"	
# define OFF	"\033[0m"

// =====CLASSES=================================================================

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string new_name);
		~Zombie();
		void	announce(void);
};

// =====FUNCTIONS===============================================================

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
