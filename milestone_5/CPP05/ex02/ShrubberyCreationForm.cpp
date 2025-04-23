/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:18:51 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 12:06:32 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("a generic ShrubberyCreationForm", 145, 137), target("a generic target")
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("a generic ShrubberyCreationForm", 145, 137), target(t)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	if (this->getSignGrade() < 1 || this->getExecuteGrade() < 1)
		throw ShrubberyCreationForm::GradeTooHighException();
	else if (this->getSignGrade() > 150 || this->getExecuteGrade() > 150)
		throw ShrubberyCreationForm::GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy) : AForm(copy)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		*this = copy;
	return *this;
}

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm const& rhs)
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
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSign())
		throw AForm::NotSigned();
	std::fstream file;
	std::string filename = target + "_shrubbery";

	file.open(filename.c_str(), std::ios::out);
	std::string tree = "	/\\      \n     /\\*\\     \n    /\\O\\*\\    \n   /*/\\/\\/\\   \n  /\\O\\/\\*\\/\\  \n /\\*\\/\\*\\/\\/\\ \n/\\O\\/\\/*/\\/O/\\\n      ||      \n      ||      \n      ||      \n";
	file << tree;
	file.close();
	std::cout << "Shrubbery has been created in " << filename << std::endl;
}