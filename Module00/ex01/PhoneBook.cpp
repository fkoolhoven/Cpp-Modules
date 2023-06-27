/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:44:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/06/27 17:59:37 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::set_Contacts(Contact new_Contact, int i)
{
	contacts[i] = new_Contact;
}

Contact	PhoneBook::get_Contacts(int i)
{
	return (contacts[i]);
}

void	print_contact_info(std::string contact_info)
{
	int	strlen;

	strlen = contact_info.length();
	if (strlen > 10)
		std::cout << std::setw(9) << std::right << contact_info.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << std::right << contact_info << '|';
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

	std::cout << "\nID        |FIRST NAME| LAST NAME|  NICKNAME|\n";
	std::cout << std::string(44, '-') << std::endl;
	for (i = 0; i < 8 && phonebook.get_Contacts(i).get_Index() >= 0; i++)
	{
		std::cout << std::setw(10) << std::left << phonebook.get_Contacts(i).get_Index() << '|';
		print_contact_info(phonebook.get_Contacts(i).get_FirstName());
		print_contact_info(phonebook.get_Contacts(i).get_LastName()); 
		print_contact_info(phonebook.get_Contacts(i).get_Nickname());
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
	while (!(std::cin >> contact_id) || contact_id < 0 || contact_id > 7
		|| phonebook.get_Contacts(contact_id).get_Index() == -1)
	{
        std::cin.clear();
       	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Choose a valid contact ID. This should be a number ranging from 0 to 7: ";
    }
	display_specific_contact(phonebook, contact_id);
}

PhoneBook	initialize_phonebook(Contact contact, PhoneBook phonebook)
{
	int i = 0;

	while (i < 8)
	{
		phonebook.set_Contacts(contact, i);
		contact.set_Index(-1);
		i++;
	}
	return (phonebook);
}
