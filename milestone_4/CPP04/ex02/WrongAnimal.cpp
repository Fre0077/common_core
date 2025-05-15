/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:07:43 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 08:53:00 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
	std::cout << "Costruction of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& copy) : type(copy.type) 
{
	std::cout << "Copy of WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "destraction of WrongAnimal" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& copy) 
{
	std::cout << "Copy operator of WrongAnimal" << std::endl;
	if (&copy != this)
		this->type = copy.type;
	return (*this);

}
//==============================================================================
//METHOD========================================================================
//==============================================================================
void	WrongAnimal::makeSound(void)
{
	std::cout << "..." << std::endl;
}

std::string WrongAnimal::getType()
{
	return (this->type);
}