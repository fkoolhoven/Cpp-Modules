/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:47:38 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/07/05 16:52:14 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <string>
# include <stdlib.h>
# include <iostream>

# include "Contact.hpp"

// =====MACROS==================================================================

# define BOLD	"\033[1m"
# define RED	"\033[31m"
# define GREEN 	"\033[32m"
# define YELLOW	"\033[33m"	
# define OFF	"\033[0m"

// =====CLASSES=================================================================

class PhoneBook
{
	private:
		Contact	contacts[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	set_Contacts(Contact new_Contact, int i);
		void	display_all_contacts(void);
		void	display_specific_contact(int contact_id);
		void	search_contact(void);
		void	add_contact_to_phonebook(int index);
};

#endif
