/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:11:41 by francesco         #+#    #+#             */
/*   Updated: 2025/04/24 12:24:01 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include "Data.hpp"

class Serialization
{
private:
	Serialization();
	Serialization(Serialization const &copy);
	Serialization &operator=(Serialization const &copy);
public:
	~Serialization();
	static unsigned long serialize(Data* ptr);
	static Data* deserialize(unsigned long raw);
};

#endif