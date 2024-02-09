/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:21:56 by felicia           #+#    #+#             */
/*   Updated: 2024/02/09 14:07:56 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

enum FormType 
{
    SHRUBBERY_CREATION,
    ROBOTOMY_REQUEST,
    PRESIDENTIAL_PARDON
};

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& src);
		~Intern(void);
		Intern& operator=(const Intern& src);

		AForm* MakeForm(std::string formName, std::string target);

		class FormDoesNotExist : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif