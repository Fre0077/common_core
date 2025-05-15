/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:27:32 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 10:00:54 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
Brain::Brain() : index(0) 
{
	std::cout << "Costruction of Brain" << std::endl;
}

Brain::Brain(Brain const& copy)
{
	std::cout << "Copy of Brain" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "destraction of Brain" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Brain&	Brain::operator=(Brain const& copy) 
{
	std::cout << "Copy operator of Brain" << std::endl;
	if (&copy != this)
		*this = copy;
	return (*this);

}
//==============================================================================
//METHOD========================================================================
//==============================================================================
void	Brain::addIdea(std::string *idea)
{
	this->ideas[this->index] = idea;
	if (index < 100)
		this->index++;
	else
		std::cout << "No more space for ideas..." << std::endl;
}

void	Brain::removeIdea()
{
	this->ideas[this->index] = NULL;
	if (index > 0)
		this->index--;
	else
		std::cout << "It can't became more stupid..." << std::endl;
}

void	Brain::showIdea(int i)
{
	if (i >= 0 && i < 100)
		std::cout << this->ideas[i] << std::endl;
	else
		std::cout << "Who do you think you're talking with?" << std::endl;
}