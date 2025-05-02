/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:38:02 by fre007            #+#    #+#             */
/*   Updated: 2025/05/02 15:40:55 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename T>
void printElement(const T& element)
{
	std::cout << element << " ";
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArraySize = sizeof(intArray) / sizeof(int);
	iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charArraySize = sizeof(charArray) / sizeof(char);
	iter(charArray, charArraySize, printElement<char>);
	std::cout << std::endl;
	std::string stringArray[] = {"Hello", "World", "GitHub", "Copilot", "is", "dumb"};
	size_t stringArraySize = sizeof(stringArray) / sizeof(std::string);
	iter(stringArray, stringArraySize, printElement<std::string>);
	std::cout << std::endl;
	std::cout << "Tests with Awesome class" << std::endl;
	return 0;
}