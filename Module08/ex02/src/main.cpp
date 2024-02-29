/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:46:07 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/29 12:28:51 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void TestWithConstMutantStack(void)
{
	std::cout << BOLD YELLOW "Testing with const mutant stack\n" OFF;

	MutantStack<int> mutant_stack;
	mutant_stack.push(11);
	mutant_stack.push(12);
	mutant_stack.push(13);

	const MutantStack<int> const_mutant(mutant_stack);
	MutantStack<int>::const_iterator begin = const_mutant.begin();
	MutantStack<int>::const_iterator end = const_mutant.end();
	while (begin != end)
	{
		std::cout << "Iterator: " << *begin << std::endl;
		++begin;
	}	
}

void TestFromSubjectWithMutantChar(void)
{
	std::cout << BOLD YELLOW "Test from subject with mutant stack (char)\n" OFF;

	MutantStack<char> mutant_stack;
	mutant_stack.push('a');
	mutant_stack.push('Z');
	std::cout << "Top: " << mutant_stack.top() << std::endl;
	mutant_stack.pop();
	std::cout << "Size: " << mutant_stack.size() << std::endl;
	mutant_stack.push('Q');
	mutant_stack.push('@');
	mutant_stack.push('|');
	mutant_stack.push('0');
	MutantStack<char>::iterator begin = mutant_stack.begin();
	MutantStack<char>::iterator end = mutant_stack.end();
	++begin;
	--begin;
	while (begin != end)
	{
		std::cout << "Iterator: " << *begin << std::endl;
		++begin;
	}
	std::stack<char> s(mutant_stack);
}

void TestFromSubjectWithListChar(void)
{
	std::cout << BOLD YELLOW "Test from subject with list (char)\n" OFF;

	std::list<char> list;
	list.push_back('a');
	list.push_back('Z');
	std::cout << "Top: " << list.back() << std::endl;
	list.pop_back();
	std::cout << "Size: " << list.size() << std::endl;
	list.push_back('Q');
	list.push_back('@');
	list.push_back('|');
	list.push_back('0');
	std::list<char>::iterator begin = list.begin();
	std::list<char>::iterator end = list.end();
	++begin;
	--begin;
	while (begin != end)
	{
		std::cout << "Iterator: " << *begin << std::endl;
		++begin;
	}
	std::list<char> s(list);
}

void TestFromSubjectWithMutantInt(void)
{
	std::cout << BOLD YELLOW "Test from subject with mutant stack (int)\n" OFF;

	MutantStack<int> mutant_stack;
	mutant_stack.push(5);
	mutant_stack.push(17);
	std::cout << "Top: " << mutant_stack.top() << std::endl;
	mutant_stack.pop();
	std::cout << "Size: " << mutant_stack.size() << std::endl;
	mutant_stack.push(3);
	mutant_stack.push(5);
	mutant_stack.push(737);
	mutant_stack.push(0);
	MutantStack<int>::iterator begin = mutant_stack.begin();
	MutantStack<int>::iterator end = mutant_stack.end();
	++begin;
	--begin;
	while (begin != end)
	{
		std::cout << "Iterator: " << *begin << std::endl;
		++begin;
	}
	std::stack<int> s(mutant_stack);
}

void TestFromSubjectWithListInt(void)
{
	std::cout << BOLD YELLOW "Test from subject with list (int)\n" OFF;

	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << "Top: " << list.back() << std::endl;
	list.pop_back();
	std::cout << "Size: " << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator begin = list.begin();
	std::list<int>::iterator end = list.end();
	++begin;
	--begin;
	while (begin != end)
	{
		std::cout << "Iterator: " << *begin << std::endl;
		++begin;
	}
	std::list<int> s(list);
}

void TestMutantStack(void)
{
	std::cout << BOLD YELLOW "Testing mutant stack\n" OFF;
	
	MutantStack<int> stack;
	stack.push(11);
	stack.push(12);
	stack.push(13);
	std::cout << "Top: " << stack.top() << std::endl;
	std::cout << "Size: " << stack.size() << std::endl;
	std::string empty = stack.empty() ? "true" : "false";
	std::cout << "Empty: " << empty << std::endl;
	std::cout << "Popping top..." << std::endl;
	stack.pop();
	std::cout << "Top: " << stack.top() << std::endl;
	std::cout << "Size: " << stack.size() << std::endl;
}

void TestRealStack(void)
{
	std::cout << BOLD YELLOW "Testing real stack\n" OFF;
	
	std::stack<int> stack;
	stack.push(11);
	stack.push(12);
	stack.push(13);
	std::cout << "Top: " << stack.top() << std::endl;
	std::cout << "Size: " << stack.size() << std::endl;
	std::string empty = stack.empty() ? "true" : "false";
	std::cout << "Empty: " << empty << std::endl;
	std::cout << "Popping top..." << std::endl;
	stack.pop();
	std::cout << "Top: " << stack.top() << std::endl;
	std::cout << "Size: " << stack.size() << std::endl;
}

void TestConstructorDestructor(void)
{
	std::cout << BOLD YELLOW "\nTesting constructor and destructor\n" OFF;
	
	MutantStack<int> stack;
	stack.push(11);

	MutantStack<int> copy1(stack);

	MutantStack<int> copy2;
	copy2 = stack;
	
	std::cout << "stack top = " << stack.top() << std::endl;
	std::cout << "copy1 top = " << copy1.top() << std::endl;
	std::cout << "copy2 top = " << copy2.top() << std::endl;

	std::cout << BOLD YELLOW "\nTesting deep copy\n" OFF;

	stack.push(12);
	copy1.push(13);
	copy2.push(14);

	std::cout << "stack top = " << stack.top() << std::endl;
	std::cout << "copy1 top = " << copy1.top() << std::endl;
	std::cout << "copy2 top = " << copy2.top() << std::endl;
}

int main(void)
{
	TestConstructorDestructor();
	std::cout << std::endl;
	TestRealStack();
	std::cout << std::endl;
	TestMutantStack();
	std::cout << std::endl;
	TestFromSubjectWithListInt();
	std::cout << std::endl;
	TestFromSubjectWithMutantInt();
	std::cout << std::endl;
	TestFromSubjectWithListChar();
	std::cout << std::endl;
	TestFromSubjectWithMutantChar();
	std::cout << std::endl;
	TestWithConstMutantStack();
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}