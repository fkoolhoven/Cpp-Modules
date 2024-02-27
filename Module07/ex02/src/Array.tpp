/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:02 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/27 15:30:44 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void) : array(nullptr), array_size(0) 
{
	std::cout << GREEN "Array created\n" OFF;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	if (n <= 0 || n > UINT_MAX)
		throw std::invalid_argument("Invalid array size");
	else
	{
		array = new T[n]; 
		array_size = n; 
		std::fill(array, array + n, T());
		std::cout << GREEN "Array created\n" OFF;
	}
}

template <typename T>
Array<T>::Array(const Array& instance) : array(new T[instance.array_size]), array_size(instance.array_size)
{
	for (unsigned int i = 0; i < instance.array_size; i++)
		array[i] = instance[i];
	std::cout << GREEN "Array copy constructed\n" OFF;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& instance)
{
	if (this != &instance)
	{
		delete[] array;
		array = new T[instance.array_size];
		array_size = instance.array_size;
		for (unsigned int i = 0; i < instance.array_size; i++)
			array[i] = instance[i];
	}
	std::cout << "Array copied\n";
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] array;
	std::cout << RED "Array destroyed\n" OFF;
}

template <typename T>
unsigned int Array<T>::getArraySize(void) const
{
	return (array_size);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= array_size)
        throw std::out_of_range("Index out of range");
    return array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= array_size)
        throw std::out_of_range("Index out of range");
    return array[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Array<T>& instance)
{
	if (instance.getArraySize() == 0)
	{
		stream << "Array is empty\n";
		return (stream);
	}
	
	for (unsigned int i = 0; i < instance.getArraySize(); i++)
		stream << instance[i] << " ";
	return (stream);
}