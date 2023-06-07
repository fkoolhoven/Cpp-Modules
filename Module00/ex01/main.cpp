/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:05:04 by felicia           #+#    #+#             */
/*   Updated: 2023/06/07 22:19:58 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void	search_for_specific_contact(PhoneBook phonebook)
{
	std::cout << "You chose SEARCH.\n";
	// Display the saved contacts as a list of 4 columns: index, first name, last
	// name and nickname.
	// ◦ Each column must be 10 characters wide. A pipe character (’|’) separates
	// them. The text must be right-aligned. If the text is longer than the column,
	// it must be truncated and the last displayable character must be replaced by a
	// dot (’.’).
	// ◦ Then, prompt the user again for the index of the entry to display. If the index
	// is out of range or wrong, define a relevant behavior. Otherwise, display the
	// contact information, one field per line.
	int i;
	for (i = 0; phonebook.contacts[i].index >= 0; i++)
	{
		std::cout << phonebook.contacts[i].index;
		std::cout << phonebook.contacts[i].first_name;
		std::cout << phonebook.contacts[i].last_name;
		std::cout << phonebook.contacts[i].nickname << std::endl;
	}
	std::string	id;
	int			id_as_int;
	std::cout << "Choose a contact ID.\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, id, '\n');
	id_as_int = stoi(id);
	std::cout << "index is: " << phonebook.contacts[id_as_int].index << std::endl;
	std::cout << "first name is: " << phonebook.contacts[id_as_int].first_name << std::endl;
	std::cout << "last name is: " << phonebook.contacts[id_as_int].last_name << std::endl;
	std::cout << "nickname is: " << phonebook.contacts[id_as_int].nickname << std::endl;
	std::cout << "phone number is: " << phonebook.contacts[id_as_int].phone_number << std::endl;
	std::cout << "darkest secret is: " << phonebook.contacts[id_as_int].darkest_secret << std::endl;
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