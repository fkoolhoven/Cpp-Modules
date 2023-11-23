/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:27 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/11/23 18:05:58 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void AnnounceOutsideMain(Zombie *heap_zombie)
{
	heap_zombie->announce();	
}

int	main(void)
{
	Zombie *heap_zombie = newZombie("John Heap");
	heap_zombie->announce();
	AnnounceOutsideMain(heap_zombie);
	delete heap_zombie;
	randomChump("Thom Stack");
	return (EXIT_SUCCESS);
}
