/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:27 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/07/11 15:26:13 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << GREEN"CONSTRUCTED ZOMBIE\n" << OFF;
}

Zombie::~Zombie(void)
{
	std::cout << RED"DESTRUCTED ZOMBIE" << name << OFF << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << BOLD GREEN << name << OFF": BraiiiiiiinnnzzzZ...\n";
}