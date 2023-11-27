/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:14:27 by felicia           #+#    #+#             */
/*   Updated: 2023/11/27 13:14:28 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int horde_size = 3;
	Zombie *zombie_horde = zombieHorde(horde_size, "Zombaby");

	for (int i = 0; i < horde_size; i++)
		zombie_horde[i].announce();
	delete[] zombie_horde;
	return (EXIT_SUCCESS);
}