/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:59:48 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/04 14:40:54 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void TestRPN(char **argv)
{
	std::cout << YELLOW BOLD "TestRPN\n" OFF;
	std::string input = argv[1];
	RPN rpn(input);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./rpn <inverted Polish mathematical expression>\n";
		return (EXIT_FAILURE);
	}

	std::cout << std::endl;
	TestRPN(argv);
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}