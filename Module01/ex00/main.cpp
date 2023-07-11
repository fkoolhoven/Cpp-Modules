/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:27 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/07/11 18:07:48 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap_zombie;

	heap_zombie = newZombie("Jurriaan Heap");
	heap_zombie->announce();
	delete heap_zombie;
	heap_zombie = newZombie("Sam Heap");
	heap_zombie->announce();
	delete heap_zombie;
	heap_zombie = newZombie("Jesse Heap");
	heap_zombie->announce();
	delete heap_zombie;
	randomChump("Erik Stack");
	randomChump("Zoey Stack");
	randomChump("Aileen Stack");
	return (EXIT_SUCCESS);
}
