/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:59:48 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/27 18:45:43 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void TestRPN(char **argv)
{
	std::cout << YELLOW BOLD "TestRPN\n" OFF;
	std::string input = argv[1];
	RPN rpn(input);
}

void TestCopyConstructor()
{
	std::cout << YELLOW BOLD "\nTestCopyConstructor\n" OFF;
	RPN rpn("3 2 +");
	RPN rpn_copy(rpn);

	std::cout << "stack1 top: " << rpn.getStack().top() << std::endl;
	std::cout << "stack2 top: " << rpn_copy.getStack().top() << std::endl;

	rpn_copy.getStack().pop();

	std::cout << "stack1 top: " << rpn.getStack().top() << std::endl;
	std::cout << "stack2 top: " << rpn_copy.getStack().top() << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./rpn <inverted Polish mathematical expression>\n";
		return (EXIT_FAILURE);
	}

	TestCopyConstructor();
	std::cout << std::endl;
	TestRPN(argv);
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}