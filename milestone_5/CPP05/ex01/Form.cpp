/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 09:54:08 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 10:38:15 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
Form::Form() : name("a generic Form"), signGrade(1), executeGrade(1)
{
	std::cout << "Form constructor called" << std::endl;
	this->sign = false;
}

Form::Form(std::string n, int signGrade, int executeGrade) : name(n), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "Form constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const& copy) : name(copy.name), sign(copy.sign), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Form&	Form::operator=(Form const& copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		*this = copy;
	return *this;
}

std::ostream& operator<<(std::ostream& out, Form const& rhs)
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
std::string const	Form::getName() const
{
	return (this->name);
}

int	Form::getSignGrade() const
{
	return (this->signGrade);
}

int	Form::getExecuteGrade() const
{
	return (this->executeGrade);
}

bool	Form::getSign() const
{
	return (this->sign);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
void	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() >= this->getSignGrade())
		throw Form::GradeTooLowException();
	this->sign = true;
}