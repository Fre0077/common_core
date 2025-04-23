/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:21:18 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 12:28:04 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern intern;

	AForm* shrubbery = intern.makeForm("shrubbery creation", "home");
	AForm* robotomy = intern.makeForm("robotomy request", "home");
	AForm* presidential = intern.makeForm("presidential pardon", "home");

	AForm* not_found = intern.makeForm("insert AForm joke here", "home");

	(void)shrubbery;
	(void)robotomy;
	(void)presidential;
	std::cout << *shrubbery << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *presidential << std::endl;
	if (not_found)
		std::cout << *not_found << std::endl;
	delete presidential;
	delete robotomy;
	delete shrubbery;
    return 0;
}