/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:24:03 by francesco         #+#    #+#             */
/*   Updated: 2025/04/20 09:39:16 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	this->grade = 1;
	this->name = "a generic Bureaucrat";
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	this->name = name;
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		*this = copy;
	return *this;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
std::string const	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade++;
}

void	Bureaucrat::decrementGrade()
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade--;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}