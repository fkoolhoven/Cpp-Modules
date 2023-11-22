/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:05:04 by felicia           #+#    #+#             */
/*   Updated: 2023/11/22 19:27:03 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;
	int			index;
	
	index = 0;
	while (true)
	{
		std::cout << YELLOW "Please choose a command: ADD, SEARCH or EXIT.\n" OFF;
		std::cin >> command;
		if (command.compare("ADD") == 0)
		{
			if (index % 8 == 0)
				index = 0;
			phonebook.AddContactToPhonebook(index);
			index++;
		}
		else if (command.compare("SEARCH") == 0)
			phonebook.SearchContact();
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << YELLOW "That command doesn't exist.\n" OFF;
	}
	std::cout << YELLOW "Exiting phonebook. Goodbye!\n" OFF;
	return (EXIT_SUCCESS);
}