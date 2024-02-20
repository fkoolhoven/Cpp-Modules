/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:46:07 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/20 18:09:18 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void TestFromSubjectWithMutant(void)
{
	std::cout << BOLD YELLOW "Test from subject with mutant stack\n" OFF;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Iterator: " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void TestFromSubjectWithList(void)
{
	std::cout << BOLD YELLOW "Test from subject with list\n" OFF;

	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "Top: " << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << "Size: " << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Iterator: " << *it << std::endl;
		++it;
	}
	std::list<int> s(mlist);
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

int main(void)
{
	std::cout << std::endl;
	TestRealStack();
	std::cout << std::endl;
	TestMutantStack();
	std::cout << std::endl;
	TestFromSubjectWithList();
	std::cout << std::endl;
	TestFromSubjectWithMutant();
	std::cout << std::endl;
}