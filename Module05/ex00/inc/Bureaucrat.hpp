/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:03:37 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/01/03 19:29:14 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A Bureaucrat must have:
// • A constant name.
// • And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible
// grade).

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# define GREEN	"\033[32m"
# define RED 	"\033[31m"
# define YELLOW	"\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat(void);
		Bureaucrat &operator=(const Bureaucrat& src);
	
		std::string	GetName(void) const;
		int			GetGrade(void) const;
		
		void	IncrementGrade(void);
		void	DecrementGrade(void);
	
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

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& instance);

#endif