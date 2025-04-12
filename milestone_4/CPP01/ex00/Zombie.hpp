/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:56 by fre007            #+#    #+#             */
/*   Updated: 2025/04/08 11:10:54 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <cctype>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie();
	void announce( void );
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif