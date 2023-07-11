/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:14:27 by felicia           #+#    #+#             */
/*   Updated: 2023/07/11 18:53:18 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		horde_size;
	Zombie	*zombie_horde;
	
	horde_size = 10;
	zombie_horde = zombieHorde(horde_size, "Zombaby");
	for (int i = 0; i < horde_size; i++)
	{
		zombie_horde[i].announce();
	}
	delete[] zombie_horde;
	zombie_horde = NULL;
}