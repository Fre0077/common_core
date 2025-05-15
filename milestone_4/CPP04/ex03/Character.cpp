/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:26:29 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/17 09:09:31 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
Character::Character() : index(0), name("a generic and cool pistolero")
{
	std::cout << "Costruction of Character" << std::endl;
	for (int i = 0; i < 4; i++)
		invetory[i] = NULL;
}

Character::Character(std::string const& name) : index(0)
{
	std::cout << "Copy of Character" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		invetory[i] = NULL;
}

Character::Character(Character const& copy)
{
	std::cout << "Copy of Character" << std::endl;
	*this = copy;
}

Character::~Character()
{
	std::cout << "destraction of Character" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Character&	Character::operator=(Character const& copy) 
{
	std::cout << "Copy operator of Character" << std::endl;
	if (&copy != this)
		*this = copy;
	return (*this);
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
std::string const & Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	if (m != NULL && this->index < 4)
	{
		std::cout << "The volcanic is loading..." << std::endl;
		this->invetory[this->index] = m;
		this->index++;
	}
	else if (m != NULL)
		std::cout << "The volcanic is ready to fire..." << std::endl;
	else
		std::cout << "A COCKROACH??? ARE YOU JOKING ME???" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->invetory[idx] != NULL)
	{
		this->invetory[idx] = NULL;
		this->index--;
	}
	else if (idx < 0 || idx >= 4)
		std::cout << "It's a volcanic not a revolver, stupid duck" << std::endl;
	else
		std::cout << "WHY THERE IS A COCKROACH IN MY VOLCANIC???" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	
	if (idx >= 0 && idx < 4 && this->invetory[idx] != NULL)
	{
		this->invetory[idx]->use(target);
		this->invetory[idx] = NULL;
		this->index--;
	}
	else if (idx < 0 || idx >= 4)
		std::cout << "It's a volcanic not a revolver!" << std::endl;
	else
		std::cout << "Sorry, my volcanic is not firing. wait a minute..." << std::endl;
}
