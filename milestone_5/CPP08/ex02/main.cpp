/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:38:02 by fre007            #+#    #+#             */
/*   Updated: 2025/05/15 15:49:14 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <deque>
#include <vector>

template <typename T, typename C>
void testContainer(T &container, C input[5]) {
	// Add elements to the container
	container.push_back(input[0]);
	container.push_back(input[1]);
	container.push_back(input[2]);
	container.push_back(input[3]);
	container.push_back(input[4]);

	// Print the elements in reverse using reverse iterators
	std::cout << "Elements in reverse: ";
	for (typename T::reverse_iterator rit = container.rbegin(); rit != container.rend(); ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << std::endl;
	std::cout << "Elements in const: ";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void testContainerPush(T &container) {
	
	container.push(10);
	container.push(20);
	container.push(30);
	container.push(40);
	container.push(50);


	std::cout << "Elements in reverse: ";
	for (typename T::reverse_iterator rit = container.rbegin(); rit != container.rend(); ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << std::endl;
	std::cout << "Elements in const: ";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main() {
	MutantStack<int> mstack;
	std::list<int> list;
	std::deque<char> deque;
	std::vector<__int32_t> vec;

	std::cout << "testContainerPush with MutantStack" << std::endl;
	testContainerPush(mstack);

	std::cout << "testContainerPush with list" << std::endl;
	testContainer(list, (int[5]){1, 2, 3, 4, 5});

	std::cout << "testContainerPush with deque" << std::endl;
	testContainer(deque, (char[5]){'a', 'b', 'c', 'd', 'e'});

	std::cout << "testContainerPush with vector" << std::endl;
	testContainer(vec, (__int32_t[5]){10000, 20000, 30000, 40000, 50000});

	return 0;
}