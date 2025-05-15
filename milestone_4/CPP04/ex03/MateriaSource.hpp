/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:06:16 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/17 08:51:06 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	Learned[10];
	int			index;

public:
	MateriaSource();
	MateriaSource(MateriaSource const& copy);
	MateriaSource& operator=(MateriaSource const& copy);
	~MateriaSource();
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};

#endif