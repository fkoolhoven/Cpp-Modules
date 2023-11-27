/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:00:59 by felicia           #+#    #+#             */
/*   Updated: 2023/11/27 16:26:34 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: expecting two arguments.\n";
		return (EXIT_FAILURE);
	}
	
	Harl	harl;
	std::string level = argv[1];
	if (level != "debug" && level != "info" && level != "warning" && level != "error")
	{
		std::cerr << "Error: expecting 'debug', 'info', "
			"'warning' or 'error' as argument\n";
		return (EXIT_FAILURE);
	}
	harl.complain(level);
	return (EXIT_SUCCESS);
}