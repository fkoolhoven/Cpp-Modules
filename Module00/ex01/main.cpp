/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:05:04 by felicia           #+#    #+#             */
/*   Updated: 2023/06/12 18:11:12 by felicia          ###   ########.fr       */
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
	for (i = 0; phonebook.contacts[i].index >= 0; i++)
	{
		std::cout << phonebook.contacts[i].index << std::string(9, ' ') << '|';
		strlen = phonebook.contacts[i].first_name.length();
		print_contact_info(phonebook.contacts[i].first_name, strlen);
		strlen = phonebook.contacts[i].last_name.length();
		print_contact_info(phonebook.contacts[i].last_name, strlen);
		strlen = phonebook.contacts[i].nickname.length();
		print_contact_info(phonebook.contacts[i].nickname, strlen);
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
	std::cout << "INDEX: " << phonebook.contacts[id_as_int].index << std::endl;
	std::cout << "FIRST NAME: " << phonebook.contacts[id_as_int].first_name << std::endl;
	std::cout << "LAST NAME: " << phonebook.contacts[id_as_int].last_name << std::endl;
	std::cout << "NICKNAME: " << phonebook.contacts[id_as_int].nickname << std::endl;
	std::cout << "PHONE NUMBER: " << phonebook.contacts[id_as_int].phone_number << std::endl;
	std::cout << "DARKEST SECRET: " << phonebook.contacts[id_as_int].darkest_secret << std::endl;
	std::cout << std::endl;
}

Contact	add_new_contact(Contact contact, int i)
{
	// Contact		contact;


	std::cout << "You chose ADD.\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	contact.index = i;
	std::cout << "Enter first name:\n";
	std::getline(std::cin, contact.first_name, '\n');
	std::cout << "Enter last name:\n";
	std::getline(std::cin, contact.last_name, '\n');
	std::cout << "Enter nickname:\n";
	std::getline(std::cin, contact.nickname, '\n');
	std::cout << "Enter phone number:\n";
	std::getline(std::cin, contact.phone_number, '\n');
	std::cout << "Enter darkest secret:\n";
	std::getline(std::cin, contact.darkest_secret, '\n');
	return (contact);
}

void	print_all_contacts(PhoneBook phonebook)
{
	int j = 0;
	
	while (j <= 8)
	{
		std::cout << "index is: " << phonebook.contacts[j].index << std::endl;
		std::cout << "first name is: " << phonebook.contacts[j].first_name << std::endl;
		std::cout << "last name is: " << phonebook.contacts[j].last_name << std::endl;
		std::cout << "nickname is: " << phonebook.contacts[j].nickname << std::endl;
		std::cout << "phone number is: " << phonebook.contacts[j].phone_number << std::endl;
		std::cout << "darkest secret is: " << phonebook.contacts[j].darkest_secret << std::endl;
		std::cout << std::endl;
		j++;
	}
}

int	main(void)
{
	Contact		contact;
	std::string	command;
	PhoneBook	phonebook;
	int			i = 0;
	
	int init = 0;
	while (init < 9)
	{
		phonebook.contacts[init].index = -1;
		init++;
	}
	while (true)
	{
		std::cout << "Please choose a command: ADD, SEARCH or EXIT.\n";
		std::cin >> command;
		if (command.compare("ADD") == 0)
		{
			if (i % 9 == 0)
				i = 0;
			contact = phonebook.contacts[i];
			phonebook.contacts[i] = add_new_contact(contact, i);
			//print_all_contacts(phonebook);
			i++;
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