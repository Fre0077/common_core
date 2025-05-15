/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:08:54 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 17:22:08 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
AMateria::AMateria() : type("AMateria") 
{
	std::cout << "Costruction of AMateria" << std::endl;
}

AMateria::AMateria(std::string const& type)
{
	std::cout << "Copy of AMateria" << std::endl;
	this->type = type;
}

AMateria::AMateria(AMateria const& copy) : type(copy.type) 
{
	std::cout << "Copy of AMateria" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "destraction of AMateria" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
AMateria&	AMateria::operator=(AMateria const& copy) 
{
	std::cout << "Copy operator of AMateria" << std::endl;
	if (&copy != this)
		this->type = copy.type;
	return (*this);
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
std::string const& AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "cosa?? " << target.getName() << std::endl;
}