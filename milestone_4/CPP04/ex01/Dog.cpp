/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:28:21 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 10:30:40 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
Dog::Dog()
{
	std::cout << "Costruction of Dog" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog const& copy)
{
	std::cout << "Copy of Dog" << std::endl;
	this->type = copy.type;
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "destraction of Dog" << std::endl;
	delete this->brain;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Dog&	Dog::operator=(Dog const& copy) 
{
	std::cout << "Copy operator of Dog" << std::endl;
	if (&copy != this)
	{
		this->type = copy.type;
		this->brain = new Brain();
	}
	return (*this);

}
//==============================================================================
//METHOD========================================================================
//==============================================================================
void	Dog::makeSound(void)
{
	std::cout << "Bau Bau!" << std::endl;
}

void Dog::addIdea(std::string *idea)
{
	this->brain->addIdea(idea);
}

void Dog::removeIdea()
{
	this->brain->removeIdea();
}

void Dog::showIdea(int i)
{
	this->brain->showIdea(i);
}