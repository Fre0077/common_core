/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:02:07 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 09:15:03 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <cctype>
# include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const& copy);
	WrongAnimal& operator=(WrongAnimal const& copy);
	virtual	~WrongAnimal();
	void makeSound(void);
	std::string getType();

protected:
	std::string type;
};

#endif