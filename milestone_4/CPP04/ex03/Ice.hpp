/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:54:12 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 17:13:44 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
protected:

public:
	Ice();
	Ice(Ice const& copy);
	~Ice();
	Ice& operator=(Ice const& copy);
	std::string const & getType() const;
	Ice* clone() const;
	void use(ICharacter& target);
};

#endif