/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:44:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/11/22 19:27:29 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << BOLD GREEN "Constructed phonebook!\n" OFF;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << BOLD RED "Destructed phonebook!\n" OFF;
}

void	PrintContactInfo(std::string contact_info)
{
	if (contact_info.length() > 10)
		std::cout << contact_info.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << std::right << contact_info << '|';
}

void	PhoneBook::DisplaySpecificContact(int index)
{
	std::cout << std::endl;
	std::cout << "INDEX: " << contacts[index].getIndex() << std::endl;
	std::cout << "FIRST NAME: " << contacts[index].getFirstName() << std::endl;
	std::cout << "LAST NAME: " << contacts[index].getLastName() << std::endl;
	std::cout << "NICKNAME: " << contacts[index].getNickname() << std::endl;
	std::cout << "PHONE NUMBER: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "DARKEST SECRET: " << contacts[index].getDarkestSecret() << std::endl;
	std::cout << std::endl; 
}

void	PhoneBook::DisplayAllContacts(void)
{
	int i;

	std::cout << "\nID        |FIRST NAME| LAST NAME|  NICKNAME|\n";
	std::cout << std::string(44, '-') << std::endl;
	for (i = 0; i < 8 && contacts[i].getIndex() >= 0; i++)
	{
		std::cout << std::setw(10) << std::left << contacts[i].getIndex() << '|';
		PrintContactInfo(contacts[i].getFirstName());
		PrintContactInfo(contacts[i].getLastName()); 
		PrintContactInfo(contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::SearchContact(void)
{
	if (contacts[0].getIndex() == -1)
	{
		std::cout << YELLOW "Add a contact before searching.\n" OFF;
		return ;
	}
	DisplayAllContacts();
	std::cout << YELLOW "Choose a valid contact ID from the ID column: " OFF;
	int index = -1;
	while (!(std::cin >> index) || index < 0 || index > 7 || contacts[index].getIndex() == -1)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << YELLOW "Choose a valid contact ID from the ID column: " OFF;
	}
	DisplaySpecificContact(index);
}

void	PhoneBook::AddContactToPhonebook(int index)
{
	contacts[index].InputContactInfo(index);
}
