/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:50:50 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/04 14:34:49 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << GREEN "PmergeMe created\n" OFF;
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
	std::cout << GREEN "PmergeMe copy created\n" OFF;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	this->vector = src.vector;
	this->deque = src.deque;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << RED "PmergeMe destroyed\n" OFF;
}

static void FinalMergeSortVector(std::vector<int>& vector, int left_bound, int middle, int right_bound) 
{
	int left_size = middle - left_bound + 1;
	int right_size = right_bound - middle;

	std::vector<int> left_vector(left_size);
	std::vector<int> right_vector(right_size);

	std::copy(vector.begin() + left_bound, vector.begin() + left_bound + left_size, left_vector.begin());
	std::copy(vector.begin() + middle + 1, vector.begin() + middle + 1 + right_size, right_vector.begin());
	
	int left = 0;
	int right = 0;
	int i = left_bound;

	while (left < left_size && right < right_size) 
	{
		if (left_vector[left] <= right_vector[right]) 
		{
			vector[i] = left_vector[left];
			left++;
		} 
		else 
		{
			vector[i] = right_vector[right];
			right++;
		}
		i++;
	}

	std::copy(left_vector.begin() + left, left_vector.end(), vector.begin() + i);
	std::copy(right_vector.begin() + right, right_vector.end(), vector.begin() + i);
}

static void InsertionSortVector(std::vector<int>& vector, int left, int right) 
{
	for (int i = left; i < right; i++) 
	{
		int to_insert = vector[i + 1];
		int j = i + 1;
		while (j > left && vector[j - 1] > to_insert) 
		{
			vector[j] = vector[j - 1];
			j--;
		}
		vector[j] = to_insert;
	}
}

static void MergeInsertionSortVector(std::vector<int>& vector, int left, int right) 
{
	if (left < right) 
	{
		if (right - left + 1 > SORTING_THRESHOLD)
		{
			int middle = left + (right - left) / 2;
			MergeInsertionSortVector(vector, left, middle);
			MergeInsertionSortVector(vector, middle + 1, right);
			FinalMergeSortVector(vector, left, middle, right);
		}
		else
		{
			InsertionSortVector(vector, left, right);
		}
	}
}

void PmergeMe::SortVector(std::vector<int>& vector)
{
	auto start = std::chrono::high_resolution_clock::now();
	MergeInsertionSortVector(vector, 0, vector.size() - 1);
	auto end = std::chrono::high_resolution_clock::now();
	
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "After sorting: " << vector << std::endl;
	std::cout << "Time to sort a range of 5 elements with vector: " << duration << " microseconds\n";
}

static void FinalMergeSortDeque(std::deque<int>& deque, int left_bound, int middle, int right_bound) 
{
	int left_size = middle - left_bound + 1;
	int right_size = right_bound - middle;

	std::deque<int> left_deque(left_size);
	std::deque<int> right_deque(right_size);

	std::copy(deque.begin() + left_bound, deque.begin() + left_bound + left_size, left_deque.begin());
	std::copy(deque.begin() + middle + 1, deque.begin() + middle + 1 + right_size, right_deque.begin());
	
	int left = 0;
	int right = 0;
	int i = left_bound;

	while (left < left_size && right < right_size) 
	{
		if (left_deque[left] <= right_deque[right]) 
		{
			deque[i] = left_deque[left];
			left++;
		} 
		else 
		{
			deque[i] = right_deque[right];
			right++;
		}
		i++;
	}

	std::copy(left_deque.begin() + left, left_deque.end(), deque.begin() + i);
	std::copy(right_deque.begin() + right, right_deque.end(), deque.begin() + i);
}

static void InsertionSortDeque(std::deque<int>& deque, int left, int right) 
{
	for (int i = left; i < right; i++) 
	{
		int to_insert = deque[i + 1];
		int j = i + 1;
		while (j > left && deque[j - 1] > to_insert) 
		{
			deque[j] = deque[j - 1];
			j--;
		}
		deque[j] = to_insert;
	}
}

static void MergeInsertionSortDeque(std::deque<int>& deque, int left, int right) 
{
	if (left < right) 
	{
		if (right - left + 1 > SORTING_THRESHOLD)
		{
			int middle = left + (right - left) / 2;
			MergeInsertionSortDeque(deque, left, middle);
			MergeInsertionSortDeque(deque, middle + 1, right);
			FinalMergeSortDeque(deque, left, middle, right);
		}
		else
		{
			InsertionSortDeque(deque, left, right);
		}
	}
}

void PmergeMe::SortDeque(std::deque<int>& deque)
{
	auto start = std::chrono::high_resolution_clock::now();
	MergeInsertionSortDeque(deque, 0, deque.size() - 1);
	auto end = std::chrono::high_resolution_clock::now();
	
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "After sorting: " << deque << std::endl;
	std::cout << "Time to sort a range of 5 elements with deque: " << duration << " microseconds\n";	
}

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& vector)
{
	for (long unsigned int i = 0; i < vector.size(); i++)
		stream << vector[i] << " ";
	return (stream);
}

std::ostream& operator<<(std::ostream& stream, const std::deque<int>& deque)
{
	for (long unsigned int i = 0; i < deque.size(); i++)
		stream << deque[i] << " ";
	return (stream);
}