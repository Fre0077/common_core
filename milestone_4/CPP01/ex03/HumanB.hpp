/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:48:46 by fre007            #+#    #+#             */
/*   Updated: 2025/04/08 18:20:04 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon		*weapon;

public:
	HumanB(std::string name);
	~HumanB();
	void	setWeapon(Weapon &weapon);
	void	attack() const;
};
