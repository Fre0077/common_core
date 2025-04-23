/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 09:54:17 by francesco         #+#    #+#             */
/*   Updated: 2025/04/23 10:35:21 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	name;
	bool				sign;
	int const			signGrade;
	int const			executeGrade;

public:
	Form();
	Form(std::string name, int signGrade, int executeGrade);
	Form(Form const& copy);
	Form& operator=(Form const& copy);
	~Form();
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	std::string const	getName() const;
	bool				getSign() const;
	void				beSigned(Bureaucrat const &b);

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
};

std::ostream& operator<<(std::ostream& out, Form const& rhs);

#endif