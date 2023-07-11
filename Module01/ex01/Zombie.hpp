/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:11:24 by felicia           #+#    #+#             */
/*   Updated: 2023/07/11 18:46:06 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iomanip>
# include <string>
# include <stdlib.h>
# include <iostream>

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
	Zombie();
	~Zombie();
	void	setName(std::string newName);
	void	announce(void);
};

// =====FUNCTIONS===============================================================

Zombie*	zombieHorde(int N, std::string name);

#endif