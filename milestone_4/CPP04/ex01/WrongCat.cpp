/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:07:43 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 08:53:00 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
WrongCat::WrongCat()
{
	std::cout << "Costruction of WrongCat" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const& copy)
{
	std::cout << "Copy of WrongCat" << std::endl;
	this->type = copy.type;
}

WrongCat::~WrongCat()
{
	std::cout << "destraction of WrongCat" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
WrongCat&	WrongCat::operator=(WrongCat const& copy) 
{
	std::cout << "Copy operator of WrongCat" << std::endl;
	if (&copy != this)
		this->type = copy.type;
	return (*this);

}
//==============================================================================
//METHOD========================================================================
//==============================================================================
void	WrongCat::makeSound(void)
{
	std::cout << "..." << std::endl;
}

std::string WrongCat::getType()
{
	return (this->type);
}