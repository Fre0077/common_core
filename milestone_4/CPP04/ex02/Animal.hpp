/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:02:07 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 10:35:56 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <cctype>
# include <string>

class Animal
{
public:
	Animal();
	Animal(Animal const& copy);
	Animal& operator=(Animal const& copy);
	virtual	~Animal();
	virtual void makeSound(void) const = 0;
	std::string getType();

protected:
	std::string type;
};

#endif