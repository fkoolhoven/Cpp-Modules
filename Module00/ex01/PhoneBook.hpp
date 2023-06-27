/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:47:38 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/06/27 17:54:44 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		void	set_Contacts(Contact new_Contact, int i);
		Contact	get_Contacts(int i);
};

PhoneBook	initialize_phonebook(Contact contact, PhoneBook phonebook);
void		search_for_specific_contact(PhoneBook phonebook);