/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:17:07 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 10:36:53 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(Cat const& copy);
	~Cat();
	Cat&	operator=(Cat const& copy);
	void 	makeSound(void) const;
	void	addIdea(std::string *idea);
	void	removeIdea();
	void	showIdea(int i);
private:
	Brain *brain;
};

#endif