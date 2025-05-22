/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:09:54 by francesco         #+#    #+#             */
/*   Updated: 2025/05/22 07:29:24 by fde-sant         ###   ########.fr       */
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
    struct FormPair {
        const char* formName;
        AForm* (Intern::*createFunc)(std::string const &target);
    };

    FormPair forms[] = {
        {"shrubbery creation", &Intern::createShrubberyCreationForm},
        {"robotomy request", &Intern::createRobotomyRequestForm},
        {"presidential pardon", &Intern::createPresidentialPardonForm}
    };

    for (size_t i = 0; i < sizeof(forms)/sizeof(forms[0]); ++i) {
        if (name == forms[i].formName) {
            std::cout << "Intern creates " << name << " AForm" << std::endl;
            return (this->*forms[i].createFunc)(target);
        }
    }
    std::cerr << FormNotFoundException().what() << name << std::endl;
    return NULL;
}