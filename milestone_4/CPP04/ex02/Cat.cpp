/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:28:21 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 10:37:07 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
Cat::Cat()
{
	std::cout << "Costruction of Cat" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(Cat const& copy)
{
	std::cout << "Copy of Cat" << std::endl;
	this->type = copy.type;
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "destraction of Cat" << std::endl;
	delete this->brain;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Cat&	Cat::operator=(Cat const& copy) 
{
	std::cout << "Copy operator of Cat" << std::endl;
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
void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow!" << std::endl;
}

void Cat::addIdea(std::string *idea)
{
	this->brain->addIdea(idea);
}

void Cat::removeIdea()
{
	this->brain->removeIdea();
}

void Cat::showIdea(int i)
{
	this->brain->showIdea(i);
}