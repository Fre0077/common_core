/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:44:12 by fre007            #+#    #+#             */
/*   Updated: 2025/04/08 16:45:35 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include <string>

class Weapon
{
private:
	std::string type;

public:
	Weapon(std::string type);
	~Weapon();
	std::string getType() const;
	void		setType(const std::string type);
};

#endif