/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:47:38 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/07/05 13:48:08 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <string>
#include <stdlib.h>
#include <iostream>

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	set_Contacts(Contact new_Contact, int i);
		// Contact	get_Contacts(int i);
		void	display_all_contacts(void);
		void	display_specific_contact(int contact_id);
		void	search_for_specific_contact(void);
};

PhoneBook	initialize_phonebook(Contact contact, PhoneBook phonebook);

#endif