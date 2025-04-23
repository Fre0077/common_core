/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:21:18 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 12:07:53 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat High("High", 1);
	Bureaucrat Low("Low", 150);

	// Test case 1: ShrubberyCreationForm
	try
	{
		ShrubberyCreationForm AForm("garden");
		// AForm.execute(Bureaucrat("John", 150));
		// AForm.execute(Bureaucrat("Jane", 137));
		High.executeForm(AForm);
		High.signForm(AForm);
		High.executeForm(AForm);
	}
	catch (std::exception &e)
	{
		std::cerr << GREEN "cacca pupu: " RESET << e.what() << std::endl;
	}

	// Test case 2: RobotomyRequestForm
	try
	{
		RobotomyRequestForm AForm("robot");
		AForm.execute(Bureaucrat("John", 72));
		AForm.execute(Bureaucrat("Jane", 45));
	}
	catch (std::exception &e)
	{
		std::cerr << BLUE " lobotomizzati: " RESET << e.what() << std::endl;
	}

	// Test case 3: PresidentialPardonForm
	try
	{
		PresidentialPardonForm AForm("president");
		AForm.execute(Bureaucrat("John", 50));
		AForm.execute(Bureaucrat("Jane", 1));
	}
	catch (std::exception &e)
	{
		std::cerr << CYAN "presidente ? " RESET << e.what() << std::endl;
	}

	return 0;
}