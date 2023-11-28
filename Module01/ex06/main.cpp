/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:00:59 by felicia           #+#    #+#             */
/*   Updated: 2023/11/28 12:18:42 by fkoolhov         ###   ########.fr       */
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
	
	Harl harl;
	std::string level = argv[1];
	harl.complain(level);
	return (EXIT_SUCCESS);
}