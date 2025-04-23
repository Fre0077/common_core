/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:19:36 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 12:07:33 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
PresidentialPardonForm::PresidentialPardonForm() : AForm("a generic PresidentialPardonForm", 25, 5), target("a generic target")
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string t) : AForm("a generic PresidentialPardonForm", 25, 5), target(t)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	if (this->getSignGrade() < 1 || this->getExecuteGrade() < 1)
		throw PresidentialPardonForm::GradeTooHighException();
	else if (this->getSignGrade() > 150 || this->getExecuteGrade() > 150)
		throw PresidentialPardonForm::GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy) : AForm(copy)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		*this = copy;
	return *this;
}

std::ostream& operator<<(std::ostream& out, PresidentialPardonForm const& rhs)
{
	out << rhs.getName() << ", Form execute grade " << rhs.getExecuteGrade() << ", Form sign grade " << rhs.getSignGrade();
	if (rhs.getSign())
		out << ", the form is signed";
	else
		out << ", the form isn't signed";
	return out;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSign())
		throw AForm::NotSigned();
	std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}