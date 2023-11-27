/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:05:04 by felicia           #+#    #+#             */
/*   Updated: 2023/11/27 15:36:10 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	command;
	int			index = 0;
	
	while (true)
	{
		std::cout << YELLOW "Please choose a command: ADD, SEARCH or EXIT.\n" OFF;
		std::getline(std::cin, command, '\n');
		if (command.compare("ADD") == 0)
		{
			if (index % 8 == 0)
				index = 0;
			phone_book.AddContactToPhonebook(index);
			index++;
		}
		else if (command.compare("SEARCH") == 0)
			phone_book.SearchContact();
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << YELLOW "That command doesn't exist.\n" OFF;
	}
	std::cout << YELLOW "Exiting phonebook. Goodbye!\n" OFF;
	return (EXIT_SUCCESS);
}