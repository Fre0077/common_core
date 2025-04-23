/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:18:41 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 12:06:06 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string const target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string t);
	ShrubberyCreationForm(ShrubberyCreationForm const& copy);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& copy);
	~ShrubberyCreationForm();
	void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, AForm const& rhs);

#endif