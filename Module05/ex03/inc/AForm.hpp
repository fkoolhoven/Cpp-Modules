/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:36:06 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/13 14:37:28 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;

	public:
		AForm(const std::string name, int grade_to_sign, int grade_to_execute);
		AForm(const AForm& src);
		virtual ~AForm(void) = 0;
		AForm &operator=(const AForm& src);

		std::string GetName(void) const;
		bool GetIsSigned(void) const;
		int GetGradeToSign(void) const;
		int GetGradeToExecute(void) const;

		void BeSigned(Bureaucrat& bureacrat);
		virtual void Execute(const Bureaucrat& executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& stream, const AForm& instance);

#endif