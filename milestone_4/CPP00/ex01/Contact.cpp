/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:30:04 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/25 11:26:43 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setContact()
{
	std::cout << "First name: ";
	std::getline(std::cin, firstName);
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkestSecret);
	if (firstName == "" || lastName == "" || nickname == ""
		|| phoneNumber == "" || darkestSecret == "")
	{
		std::cout << "all field must be filled!" << std::endl;
		setContact();
	}
}

void	Contact::displayShort(int index)
{
	std::cout << std::setw(10) << index + 1 << "|"
				<< std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|"
				<< std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|"
				<< std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << std::endl;

}

void	Contact::displayFull()
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

bool Contact::isEmpty()
{
    return firstName.empty();
}