/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:44:43 by francesco         #+#    #+#             */
/*   Updated: 2025/04/24 11:47:44 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <algorithm>
# include <iostream>
# include <iomanip>
# include <set>
# include <climits>

int		 	get_type(std::string const &str);
void		charLiteral(std::string const &str);
void		PseudoLiteral(std::string const &str);
void		floatLiteral(std::string const &str);
void		doubleLiteral(std::string const &str);
void		intLiteral(std::string const &str);

#endif