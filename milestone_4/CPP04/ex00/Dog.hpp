/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:17:07 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 08:59:28 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(Dog const& copy);
	~Dog();
	Dog&	operator=(Dog const& copy);
	void makeSound(void);

private:
};

#endif