/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:19:14 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 12:07:08 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
RobotomyRequestForm::RobotomyRequestForm() : AForm("a generic RobotomyRequestForm", 72, 45), target("a generic target")
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string t) : AForm("a generic RobotomyRequestForm", 72, 45), target(t)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	if (this->getSignGrade() < 1 || this->getExecuteGrade() < 1)
		throw RobotomyRequestForm::GradeTooHighException();
	else if (this->getSignGrade() > 150 || this->getExecuteGrade() > 150)
		throw RobotomyRequestForm::GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy) : AForm(copy)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		*this = copy;
	return *this;
}

std::ostream& operator<<(std::ostream& out, RobotomyRequestForm const& rhs)
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
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSign())
		throw AForm::NotSigned();
	int ran = random() % 2;

	if (ran == 0)
		std::cout << "Drilling noises... " << target << " has been robotomized" << std::endl;
	else
		std::cout << "Drilling noises... " << target << " robotomization failed" << std::endl;
}