/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:54:21 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 17:13:41 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
protected:

public:
	Cure();
	Cure(Cure const& copy);
	~Cure();
	Cure& operator=(Cure const& copy);
	std::string const & getType() const;
	Cure* clone() const;
	void use(ICharacter& target);
};

#endif