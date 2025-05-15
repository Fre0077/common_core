/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:37:16 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 17:19:52 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <cctype>
# include <string>
# include "ICharacter.hpp" 

class ICharacter;

class AMateria
{
protected:
	std::string type;

public:
	AMateria();
	AMateria(std::string const& type);
	AMateria(AMateria const& copy);
	virtual ~AMateria();
	AMateria& operator=(AMateria const& copy);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif