/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:19:28 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 12:07:21 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string const target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string t);
	PresidentialPardonForm(PresidentialPardonForm const& copy);
	PresidentialPardonForm& operator=(PresidentialPardonForm const& copy);
	~PresidentialPardonForm();
	void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, AForm const& rhs);

#endif