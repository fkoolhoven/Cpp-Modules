/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:05:04 by felicia           #+#    #+#             */
/*   Updated: 2023/06/12 19:47:48 by felicia          ###   ########.fr       */
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

void	search_for_specific_contact(PhoneBook phonebook)
{
	int i;
	int	strlen;

	std::cout << "\nID        |FIRST NAME| LAST NAME|  NICKNAME|\n";
	std::cout << std::string(44, '-') << std::endl;
	for (i = 0; i < 8 && phonebook.contacts[i].get_Index() >= 0; i++)
	{
		std::cout << phonebook.contacts[i].get_Index() << std::string(9, ' ') << '|';
		strlen = phonebook.contacts[i].get_FirstName().length();
		print_contact_info(phonebook.contacts[i].get_FirstName(), strlen);
		strlen = phonebook.contacts[i].get_LastName().length();
		print_contact_info(phonebook.contacts[i].get_LastName(), strlen);
		strlen = phonebook.contacts[i].get_Nickname().length();
		print_contact_info(phonebook.contacts[i].get_Nickname(), strlen);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	std::string	id;
	int			id_as_int;
	std::cout << "Choose a contact ID.\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, id, '\n');
	id_as_int = stoi(id);
	// what if invalid input
	
	std::cout << std::endl;
	std::cout << "INDEX: " << phonebook.contacts[id_as_int].get_Index() << std::endl;
	std::cout << "FIRST NAME: " << phonebook.contacts[id_as_int].get_FirstName() << std::endl;
	std::cout << "LAST NAME: " << phonebook.contacts[id_as_int].get_LastName() << std::endl;
	std::cout << "NICKNAME: " << phonebook.contacts[id_as_int].get_Nickname() << std::endl;
	std::cout << "PHONE NUMBER: " << phonebook.contacts[id_as_int].get_PhoneNumber() << std::endl;
	std::cout << "DARKEST SECRET: " << phonebook.contacts[id_as_int].get_DarkestSecret() << std::endl;
	std::cout << std::endl;
}

Contact	add_new_contact(Contact contact, int i)
{
	std::string	input;

	std::cout << "You chose ADD.\n";
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
		phonebook.contacts[init].set_Index(-1);
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
			contact = phonebook.contacts[index];
			phonebook.contacts[index] = add_new_contact(contact, index);
			index++;
		}
		else if (command.compare("SEARCH") == 0)
		{
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
	
	return (3);
}