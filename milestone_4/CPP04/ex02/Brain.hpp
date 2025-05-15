/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:22:20 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 10:16:39 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain
{
public:
	Brain();
	Brain(Brain const& copy);
	virtual ~Brain();
	Brain& operator=(Brain const& copy);
	void	addIdea(std::string *idea);
	void	removeIdea();
	void	showIdea(int i);

protected:
	int			index;
	std::string *ideas[100];
};

#endif