/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:05:04 by felicia           #+#    #+#             */
/*   Updated: 2023/06/06 18:57:00 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void	search_for_specific_contact()
{
	std::cout << "You chose SEARCH.\n";
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

void	print_all_contacts(PhoneBook pb, int i)
{
	int j = 0;
	std::cout << pb.array[j].first_name;
	while (j <= i)
	{
		std::cout << "index is: " << pb.array[j].index << std::endl;
		std::cout << "first name is: " << pb.array[j].first_name << std::endl;
		std::cout << "last name is: " << pb.array[j].last_name << std::endl;
		std::cout << "nickname is: " << pb.array[j].nickname << std::endl;
		std::cout << "phone number is: " << pb.array[j].phone_number << std::endl;
		std::cout << "darkest secret is: " << pb.array[j].darkest_secret << std::endl;
		std::cout << std::endl;
		j++;
	}
}

int	main(void)
{
	Contact		contact;
	std::string	command;
	PhoneBook	pb;
	int			i = 0;
	

	while (true)
	{
		std::cout << "Please choose a command: ADD, SEARCH or EXIT.\n";
		std::cin >> command;
		if (command.compare("ADD") == 0)
		{
			contact = pb.array[i];
			pb.array[i] = add_new_contact(contact, i);
			print_all_contacts(pb, i);
			i++;
		}
		else if (command.compare("SEARCH") == 0)
		{
			search_for_specific_contact();
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