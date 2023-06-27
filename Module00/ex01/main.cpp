/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:05:04 by felicia           #+#    #+#             */
/*   Updated: 2023/06/27 17:55:26 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	Contact		contact;
	std::string	command;
	PhoneBook	phonebook;
	int			index;
	
	phonebook = initialize_phonebook(contact, phonebook);
	index = 0;
	while (true)
	{
		std::cout << "Please choose a command: ADD, SEARCH or EXIT.\n";
		std::cin >> command;
		if (command.compare("ADD") == 0)
		{
			if (index % 8 == 0)
				index = 0;
			contact = phonebook.get_Contacts(index);
			phonebook.set_Contacts(add_new_contact(contact, index), index);
			index++;
		}
		else if (command.compare("SEARCH") == 0)
		{
			if (phonebook.get_Contacts(0).get_Index() == -1)
				std::cout << "Add a contact before searching.\n";
			else
				search_for_specific_contact(phonebook);
		}
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << "That command doesn't exist, please choose ADD, SEARCH or EXIT.\n";
	}
	std::cout << "Exiting phonebook. Goodbye!\n";
	return (EXIT_SUCCESS);
}