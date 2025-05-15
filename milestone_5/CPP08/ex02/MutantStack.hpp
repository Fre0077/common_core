/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:10:32 by fde-sant          #+#    #+#             */
/*   Updated: 2025/05/15 15:51:25 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <stack>
# include <vector>
# include <iostream>
# include <climits>
# include <iomanip>
# include <set>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &copy);
		virtual ~MutantStack();
		MutantStack &operator=(MutantStack const &copy);
		typedef typename std::stack<T>::container_type container_type;

		typedef typename container_type::iterator iterator;
		iterator begin();
		iterator end();

		typedef typename container_type::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;

		typedef typename container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();

		typedef typename container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;

		using std::stack<T>::push;
		using std::stack<T>::pop;
};

# include "MutantStack.tpp"

#endif