/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:36:06 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/13 13:55:57 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;

	public:
		Form(const std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form& src);
		~Form(void);
		Form &operator=(const Form& src);

		std::string GetName(void) const;
		bool GetIsSigned(void) const;
		int GetGradeToSign(void) const;
		int GetGradeToExecute(void) const;

		void BeSigned(Bureaucrat& bureacrat);

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
};

std::ostream& operator<<(std::ostream& stream, const Form& instance);

#endif