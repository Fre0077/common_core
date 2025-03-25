/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:29:14 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/25 12:27:03 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0), size(0) {}

void PhoneBook::addContact()
{
	contacts[nextIndex].setContact();
	nextIndex = (nextIndex + 1) % 8;
	if (size < 8) size++;
}

void PhoneBook::searchContact()
{
	if (size == 0) {
		std::cout << "No contacts available." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < size; i++) {
		contacts[i].displayShort(i);
	}
	std::cout << "Enter index: ";
	int index;
	std::cin >> index;
	std::cin.ignore();
	if (std::cin.fail() || index <= 0 || index > size) {
		std::cin.clear();
		std::cin.ignore(2147483648, '\n');
		std::cout << "Invalid index!" << std::endl;
	} else {
		contacts[index - 1].displayFull();
	}
}