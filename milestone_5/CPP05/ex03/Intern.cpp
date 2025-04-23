/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:09:54 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 12:11:42 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
Intern::Intern()
{
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern::~Intern()
{
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Intern &Intern::operator=(Intern const &copy)
{
	if (this == &copy)
		return *this;
	return *this;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
AForm* Intern::createShrubberyCreationForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Did not find the AForm :";
}

AForm* Intern::makeForm(std::string const &name, std::string const &target)
{

	std::map<std::string, AForm* (Intern::*)(std::string const &target)> form_map;
	form_map["shrubbery creation"] = &Intern::createShrubberyCreationForm;
    form_map["robotomy request"] = &Intern::createRobotomyRequestForm;
    form_map["presidential pardon"] = &Intern::createPresidentialPardonForm;
	try
	{
		if (form_map.find(name) != form_map.end())
		{
			std::cout << "Intern creates " << name << " AForm" << std::endl;
			return (this->*form_map[name])(target);
		}
		throw FormNotFoundException();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << name << std::endl;
		return NULL;
	}
}