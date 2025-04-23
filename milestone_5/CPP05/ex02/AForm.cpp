/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 09:54:08 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 10:38:15 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
AForm::AForm() : name("a generic AForm"), signGrade(1), executeGrade(1)
{
	std::cout << "Form constructor called" << std::endl;
	this->sign = false;
}

AForm::AForm(std::string n, int signGrade, int executeGrade) : name(n), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "Form constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	this->sign = false;
}

AForm::AForm(AForm const& copy) : name(copy.name), sign(copy.sign), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form Destructor called" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
AForm&	AForm::operator=(AForm const& copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		*this = copy;
	return *this;
}

std::ostream& operator<<(std::ostream& out, AForm const& rhs)
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
std::string const	AForm::getName() const
{
	return (this->name);
}

int	AForm::getSignGrade() const
{
	return (this->signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (this->executeGrade);
}

bool	AForm::getSign() const
{
	return (this->sign);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high...");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low...");
}

const char *AForm::NotSigned::what() const throw()
{
	return ("The form is not signed...");
}

void	AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() >= this->getSignGrade())
		throw AForm::GradeTooLowException();
	this->sign = true;
}