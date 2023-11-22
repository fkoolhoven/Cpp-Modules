/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:47:38 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/11/22 19:04:41 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# include <iomanip>
# include <string>
# include <limits>

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
		void	SetContacts(Contact new_Contact, int i);
		void	DisplayAllContacts(void);
		void	DisplaySpecificContact(int contact_id);
		void	SearchContact(void);
		void	AddContactToPhonebook(int index);
};

#endif
