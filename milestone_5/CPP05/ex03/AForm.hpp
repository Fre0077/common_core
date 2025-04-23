/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 09:54:17 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 12:27:42 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const	name;
	bool				sign;
	int const			signGrade;
	int const			executeGrade;

public:
	AForm();
	AForm(std::string name, int signGrade, int executeGrade);
	AForm(AForm const& copy);
	AForm& operator=(AForm const& copy);
	virtual ~AForm();
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	std::string const	getName() const;
	bool				getSign() const;
	void				beSigned(Bureaucrat const &b);
	virtual void		execute(Bureaucrat const & executor) const = 0;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NotSigned : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, AForm const& rhs);

#endif