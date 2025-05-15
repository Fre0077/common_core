/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:39:26 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/17 08:02:57 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
Cure::Cure() : AMateria("cure") 
{
	std::cout << "Costruction of Cure" << std::endl;
}

Cure::Cure(Cure const& copy) : AMateria(copy.type) 
{
	std::cout << "Copy of Cure" << std::endl;
}

Cure::~Cure()
{
	std::cout << "destraction of Cure" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Cure&	Cure::operator=(Cure const& copy) 
{
	std::cout << "Copy operator of Cure" << std::endl;
	if (&copy != this)
		this->type = copy.type;
	return (*this);
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
std::string	const& Cure::getType() const
{
	return (this->type);
}

Cure*	Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}