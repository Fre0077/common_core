/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:21:18 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 10:36:08 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << GREEN "||||||BUREAUCRAT INSTATIATE TESTS||||||\n" RESET << std::endl;

	try {
		std::cout << BLUE "Trying to create a bureaucrat with a grade of 0:" RESET << std::endl;
		Bureaucrat tooHigh("TooHigh", 0);
	} catch (std::exception &e) {
		std::cerr << RED "Exception: " RESET << e.what() << RESET << std::endl;
	}

	try {
		std::cout << BLUE "Trying to create a bureaucrat with a grade of 151:" RESET << std::endl;
		Bureaucrat tooLow("TooLow", 151);
	} catch (std::exception &e) {
		std::cerr << RED "Exception: " RESET << e.what() << RESET << std::endl;
	}

	Bureaucrat bureaucrat_0;
	Bureaucrat bureaucrat_1("Jack", 75);

	std::cout << GREEN "\n||||||BUREAUCRAT TESTS||||||\n" RESET << std::endl;

	try {
		std::cout << BLUE "-----Before Decrement-----" RESET << std::endl;
		std::cout << "Bureaucrat name:" << bureaucrat_0.getName() << std::endl;
		std::cout << "Bureaucrat grade:" GREEN << bureaucrat_0.getGrade() << std::endl;

		std::cout << BLUE "-----After Decrement-----" RESET << std::endl;
		bureaucrat_0.decrementGrade();
		std::cout << "Bureaucrat name:" << bureaucrat_0.getName() << std::endl;
		std::cout << "Bureaucrat grade:" GREEN << bureaucrat_0.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << BLUE "-----Before Increment-----" RESET << std::endl;
		std::cout << "Bureaucrat name:" << bureaucrat_1.getName() << std::endl;
		std::cout << "Bureaucrat grade:" GREEN << bureaucrat_1.getGrade() << std::endl;

		std::cout << BLUE "-----After Increment-----" RESET << std::endl;
		bureaucrat_1.incrementGrade();
		std::cout << "Bureaucrat name:" << bureaucrat_1.getName() << std::endl;
		std::cout << "Bureaucrat grade:" GREEN << bureaucrat_1.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN "\n||||||FORM TESTS||||||\n" RESET << std::endl;

	Form form_0;
	Form form_1("Form_1", 80, 80);

	try {
		std::cout << BLUE "-----Trying to sign-----" RESET << std::endl;
		std::cout << "Bureaucrat name:" << bureaucrat_0.getName() << std::endl;
		std::cout << "Bureaucrat grade:" GREEN << bureaucrat_0.getGrade() << RESET << std::endl;
		bureaucrat_0.signForm(form_0);
		form_0.beSigned(bureaucrat_1);
	} catch (std::exception &e) {
		std::cerr << RESET RED "Exception: " << e.what() << RESET << std::endl;
	}
	return (0);
}