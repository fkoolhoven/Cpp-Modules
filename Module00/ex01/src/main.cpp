/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:05:04 by felicia           #+#    #+#             */
/*   Updated: 2023/07/05 13:49:55 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	Contact		contact;
	std::string	command;
	int			index;
	
	index = 0;
	while (true)
	{
		std::cout << "Please choose a command: ADD, SEARCH or EXIT.\n";
		std::cin >> command;
		if (command.compare("ADD") == 0)
		{
			if (index % 8 == 0)
				index = 0;
			contact = Contact();
			std::cout << "\n\nCONSTRUCTED CONTACT\n\n";
			contact.add_new_contact(index);	
			std::cout << "\n\nADDED CONTACT\n\n";
			phonebook.set_Contacts(contact, index);
			std::cout << "\n\nSET CONTACT\n\n";
			phonebook.display_all_contacts();
			std::cout << "\n\nDISPLAYED CONTACTS\n\n";
			index++;
		}
		else if (command.compare("SEARCH") == 0)
		{
			// if (phonebook.contacts[0].get_Index() == -1)
			// 	std::cout << "Add a contact before searching.\n";
			// else
				phonebook.search_for_specific_contact();
		}
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << "That command doesn't exist, please choose ADD, SEARCH or EXIT.\n";
	}
	std::cout << "Exiting phonebook. Goodbye!\n";
	return (EXIT_SUCCESS);
}