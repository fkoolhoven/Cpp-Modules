/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:05:04 by felicia           #+#    #+#             */
/*   Updated: 2023/06/13 16:43:06 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void	print_contact_info(std::string contact_info, int strlen)
{
	if (strlen > 10)
		std::cout << contact_info.substr(0, 9) << ".|";
	else
		std::cout << std::string(10 - strlen, ' ') << contact_info << '|';
}

void	display_specific_contact(PhoneBook phonebook, int contact_id)
{
	std::cout << std::endl;
	std::cout << "INDEX: " << phonebook.get_Contacts(contact_id).get_Index() << std::endl;
	std::cout << "FIRST NAME: " << phonebook.get_Contacts(contact_id).get_FirstName() << std::endl;
	std::cout << "LAST NAME: " << phonebook.get_Contacts(contact_id).get_LastName() << std::endl;
	std::cout << "NICKNAME: " << phonebook.get_Contacts(contact_id).get_Nickname() << std::endl;
	std::cout << "PHONE NUMBER: " << phonebook.get_Contacts(contact_id).get_PhoneNumber() << std::endl;
	std::cout << "DARKEST SECRET: " << phonebook.get_Contacts(contact_id).get_DarkestSecret() << std::endl;
	std::cout << std::endl;
}

void	display_all_contacts(PhoneBook phonebook)
{
	int i;
	int	strlen;

	std::cout << "\nID        |FIRST NAME| LAST NAME|  NICKNAME|\n";
	std::cout << std::string(44, '-') << std::endl;
	for (i = 0; i < 8 && phonebook.get_Contacts(i).get_Index() >= 0; i++)
	{
		std::cout << phonebook.get_Contacts(i).get_Index() << std::string(9, ' ') << '|';
		strlen = phonebook.get_Contacts(i).get_FirstName().length();
		print_contact_info(phonebook.get_Contacts(i).get_FirstName(), strlen);
		strlen = phonebook.get_Contacts(i).get_LastName().length();
		print_contact_info(phonebook.get_Contacts(i).get_LastName(), strlen);
		strlen = phonebook.get_Contacts(i).get_Nickname().length();
		print_contact_info(phonebook.get_Contacts(i).get_Nickname(), strlen);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	search_for_specific_contact(PhoneBook phonebook)
{
	int contact_id;
	
	display_all_contacts(phonebook);
	contact_id = -1;
	std::cout << "Choose a valid contact ID. This should be a number ranging from 0 to 7: ";
	while (!(std::cin >> contact_id) || contact_id < 0 || contact_id > 7 || phonebook.get_Contacts(contact_id).get_Index() == -1) // rewrite
	{
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Choose a valid contact ID. This should be a number ranging from 0 to 7: ";
    }
	display_specific_contact(phonebook, contact_id);
}

Contact	add_new_contact(Contact contact, int i)
{
	std::string	input;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	contact.set_Index(i);
	std::cout << "Enter first name:\n";
	std::getline(std::cin, input, '\n');
	contact.set_FirstName(input);
	std::cout << "Enter last name:\n";
	std::getline(std::cin, input, '\n');
	contact.set_LastName(input);
	std::cout << "Enter nickname:\n";
	std::getline(std::cin, input, '\n');
	contact.set_Nickname(input);
	std::cout << "Enter phone number:\n";
	std::getline(std::cin, input, '\n');
	contact.set_PhoneNumber(input);
	std::cout << "Enter darkest secret:\n";
	std::getline(std::cin, input, '\n');
	contact.set_DarkestSecret(input);
	return (contact);
}

int	main(void)
{
	Contact		contact;
	std::string	command;
	PhoneBook	phonebook;
	int			index;
	
	int init = 0;
	while (init < 8)
	{
		phonebook.set_Contacts(contact, init);
		contact.set_Index(-1);
		init++;
	}
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
		{
			std::cout << "Exiting phonebook.\n";
			break ;
		}
		else
			std::cout << "That command doesn't exist, please choose ADD, SEARCH or EXIT.\n";
	}
	return (EXIT_SUCCESS);
}