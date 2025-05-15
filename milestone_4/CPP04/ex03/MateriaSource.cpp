/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:11:35 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/17 09:10:40 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
MateriaSource::MateriaSource() : index(0)
{
	std::cout << "Costruction of MateriaSource" << std::endl;
	for (int i = 0; i < 10; i++)
		this->Learned[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& copy) 
{
	std::cout << "Copy of MateriaSource" << std::endl;
	if (&copy != this)
		*this = copy;
}

MateriaSource::~MateriaSource()
{
	std::cout << "destraction of MateriaSource" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
MateriaSource&	MateriaSource::operator=(MateriaSource const& copy) 
{
	std::cout << "Copy operator of MateriaSource" << std::endl;
	if (&copy != this)
		*this = copy;
	return (*this);
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
void	MateriaSource::learnMateria(AMateria* mat)
{
	if (!mat)
		return ;
	for (int i = 0; i < 10; i++)
		if (this->Learned[i] && mat->getType() == this->Learned[i]->getType())
		{
			std::cout << "already known materia" << std::endl;
			return ;
		}
	if (index < 10)
	{
		this->Learned[this->index] = mat;
		this->index++;
	}
	else
		std::cout << "I'm already too intelligent!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 10; i++)
		if (this->Learned[i] && type == this->Learned[i]->getType())
			return (this->Learned[i]->clone());
	std::cout << "I never seen this " << type << " or what ever..." << std::endl;
	return (NULL);
}