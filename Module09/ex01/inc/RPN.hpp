/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:59:38 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/17 10:51:34 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define GREEN		"\033[32m"
# define RED 		"\033[31m"
# define YELLOW		"\033[33m"
# define BOLD		"\033[1m"
# define OFF		"\033[0m"

# include <iostream>
# include <cstdlib>
# include <stack>
# include <string>
# include <sstream>

class RPN
{
	private:
		std::stack<float> stack;
		
	public:
		RPN(void);
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN(void);

		void CalculateRPN(std::string input);
		std::stack<float>& getStack(void);
};

#endif