/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:11:50 by francesco         #+#    #+#             */
/*   Updated: 2025/04/24 12:24:47 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
Serialization::Serialization()
{
}

Serialization::Serialization(Serialization const &copy)
{
	*this = copy;
}


Serialization::~Serialization()
{
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Serialization &Serialization::operator=(Serialization const &rhs)
{
	(void)rhs;
	return *this;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
unsigned long Serialization::serialize(Data* ptr)
{
    return reinterpret_cast<unsigned long>(ptr);
}

Data* Serialization::deserialize(unsigned long raw)
{
    return reinterpret_cast<Data*>(raw);
}