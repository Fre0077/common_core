/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:58:07 by lmicheli          #+#    #+#             */
/*   Updated: 2025/06/03 18:22:41 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t jacobsthal(int i)
{
	if (i < 0)
		return 0;
	if (i >= 2)
		i++;
	return (static_cast<size_t>((std::pow(2, i) - std::pow(-1, i)) / 3));
}

template<typename T>
void	check(T &sequence)
{
	if (sequence.size() == 2)
	{
		if (sequence[0] < sequence[1])
		{
			int val = sequence[0];
			sequence[0] = sequence[1];
			sequence[1] = val;
		}
	}
}

template<typename T>
void	take_pairs(T &main, T &pending, T &sequence)
{
	size_t i = 0;
	for (; i + 1 < sequence.size(); i += 2)
	{
		if (sequence[i] >= sequence[i + 1])
		{
			main.push_back(sequence[i]);
			pending.push_back(sequence[i + 1]);
		}
		else
		{
			main.push_back(sequence[i + 1]);
			pending.push_back(sequence[i]);
		}
	}
	if (i < sequence.size())
		main.push_back(sequence[i]);
}

void insert(std::vector<int> &main, int pending)
{
	std::vector<int>::iterator it = main.begin();
	while (it != main.end() && *it >= pending)
		++it;
	main.insert(it, pending);
}

void insert(std::deque<int> &main, int pending)
{
	std::deque<int>::iterator it = main.begin();
	while (it != main.end() && *it >= pending)
		++it;
	main.insert(it, pending);
}

void	sort(std::vector<int> &sequence)
{
	if (sequence.size() <= 2)
		return (check(sequence));
	std::vector<int> main;
	std::vector<int> pending;
	take_pairs(main, pending, sequence);
	sort(main);
	for (size_t i = 0; jacobsthal(i) <= pending.size() - 1; i++)
		insert(main, pending[jacobsthal(i)]);
	int j = 0;
	for (size_t i = 0; i < pending.size(); i++)
	{
		if (i != jacobsthal(j))
			insert(main, pending[i]);
		else
			j++;
	}
	sequence = main;
}

void	sort(std::deque<int> &sequence)
{
	if (sequence.size() <= 2)
		return (check(sequence));
	std::deque<int> main;
	std::deque<int> pending;
	take_pairs(main, pending, sequence);
	sort(main);
	for (size_t i = 0; jacobsthal(i) < pending.size() - 1; i++)
		insert(main, pending[jacobsthal(i)]);
	int j = 0;
	for (size_t i = 0; i < pending.size(); i++)
	{
		if (i != jacobsthal(j))
			insert(main, pending[i]);
		else
			j++;
	}
	sequence = main;
}