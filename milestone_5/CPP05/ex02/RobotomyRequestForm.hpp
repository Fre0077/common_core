/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:19:07 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 12:06:54 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string const target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string t);
	RobotomyRequestForm(RobotomyRequestForm const& copy);
	RobotomyRequestForm& operator=(RobotomyRequestForm const& copy);
	~RobotomyRequestForm();
	void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, AForm const& rhs);

#endif