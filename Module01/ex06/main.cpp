/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:00:59 by felicia           #+#    #+#             */
/*   Updated: 2023/11/23 18:12:03 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "Error: expecting two arguments.\n";
		return (EXIT_FAILURE);
	}
	if (strcmp(argv[1], "debug") != 0 && strcmp(argv[1], "info") != 0 // use compare instead of strcmp?
		&& strcmp(argv[1], "warning") != 0 && strcmp(argv[1], "error") != 0)
	{
		std::cout << RED "Error: expecting 'debug', 'info', "
			"'warning' or 'error' as argument\n" OFF;
		return (EXIT_FAILURE);
	}
	harl.complain(argv[1]);
	return (EXIT_SUCCESS);
}