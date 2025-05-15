/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:03:12 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 16:36:47 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria	*invetory[4];
	int			index;
	std::string	name;

public:
	Character();
	Character(std::string const& name);
	Character(Character const& copy);
	Character& operator=(Character const& copy);
	~Character();
	std::string const & getName() const;
	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
};

#endif