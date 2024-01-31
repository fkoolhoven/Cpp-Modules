/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:36:06 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/01/31 18:50:56 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

// Then, let’s make a Form class. It has:
// • A constant name.
// • A boolean indicating whether it is signed (at construction, it’s not).
// • A constant grade required to sign it.
// • And a constant grade required to execute it.
// All these attributes are private, not protected.

// The grades of the Form follow the same rules that apply to the Bureaucrat. Thus,
// the following exceptions will be thrown if a form grade is out of bounds:
// Form::GradeTooHighException and Form::GradeTooLowException.
// Same as before, write getters for all attributes and an overload of the insertion («)
// operator that prints all the form’s informations.

// Add also a beSigned() member function to the Form that takes a Bureaucrat as
// parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
// (higher or egal to the required one). Remember, grade 1 is higher than grade 2.
// If the grade is too low, throw a Form::GradeTooLowException.

// Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
// it will print something like:
// <bureaucrat> signed <form>
// Otherwise, it will print something like:
// <bureaucrat> couldn’t sign <form> because <reason>.

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