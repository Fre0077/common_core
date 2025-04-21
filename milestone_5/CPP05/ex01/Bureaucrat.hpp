/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:24:05 by francesco         #+#    #+#             */
/*   Updated: 2025/04/20 09:27:25 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <cctype>
# include <string>

class Bureaucrat
{
private:
	std::string	name;
	int			grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const& copy);
	Bureaucrat& operator=(Bureaucrat const& copy);
	~Bureaucrat();
	std::string const	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();

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

std::ostream& operator<<(std::ostream& out, Bureaucrat const& rhs);

#endif