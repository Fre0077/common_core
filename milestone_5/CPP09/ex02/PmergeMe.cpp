/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:58:07 by lmicheli          #+#    #+#             */
/*   Updated: 2025/05/31 09:59:00 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
SortDeez::SortDeez(char **av)
{
	parse(av);
	sort();
	// print();
}

SortDeez::SortDeez(SortDeez const &copy)
{
	*this = copy;
}

SortDeez::~SortDeez(void) {}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
SortDeez &SortDeez::operator=(SortDeez const &copy)
{
	if (this != &copy)
	{
		m_list = copy.m_list;
		m_vector = copy.m_vector;
	}
	return *this;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
bool SortDeez::isInt(std::string str)
{
	std::istringstream iss(str);
	int f;
	if (!(iss >> f))
		return false;
	char c;
	if (iss >> c)
		return false;
	if (f < 0)
		return false;
	return true;
}

void SortDeez::parse(char **av)
{
	for (int i = 0; av[i]; i++)
	{
		if (isInt(av[i]))
		{
			m_list.push_back(std::atoi(av[i]));
			m_vector.push_back(std::atoi(av[i]));
		}
		else
		{
			std::cout << "Error: " << av[i] << " is not a valid number" << std::endl;
			exit(1);
		}
	}
}

template <typename T>
void mergeVector(std::vector<T> &result, unsigned int startLeft, unsigned int middle, unsigned int endRight)
{
	std::vector<T> vecLeft(result.begin() + startLeft, result.begin() + middle + 1);
	std::vector<T> vecRight(result.begin() + middle + 1, result.begin() + endRight + 1);

	unsigned int iLeft = 0;
	unsigned int iRight = 0;
	unsigned int index = startLeft;
	while (iLeft < vecLeft.size() && iRight < vecRight.size())
	{
		if (vecLeft[iLeft] <= vecRight[iRight])
			result[index++] = vecLeft[iLeft++];
		else
			result[index++] = vecRight[iRight++];
	}

	while (iLeft < vecLeft.size())
		result[index++] = vecLeft[iLeft++];

	while (iRight < vecRight.size())
		result[index++] = vecRight[iRight++];
}

template <typename T>
void mergeSort(std::vector<T> &vec, unsigned int left, unsigned int right)
{
	if (left < right)
	{
		unsigned int middle = left + (right - left) / 2;
		mergeSort(vec, left, middle);
		mergeSort(vec, middle + 1, right);
		mergeVector(vec, left, middle, right);
	}
}

template <typename T>
std::list<T> mergeList(typename std::list<T>::iterator startLeft, typename std::list<T>::iterator middle, typename std::list<T>::iterator endRight)
{
    std::list<T> result;
    typename std::list<T>::iterator left = startLeft;
    typename std::list<T>::iterator right = middle;

    while (left != middle && right != endRight)
    {
        if (*left < *right)
        {
            result.push_back(*left);
            ++left;
        }
        else
        {
            result.push_back(*right);
            ++right;
        }
    }

    while (left != middle)
    {
        result.push_back(*left);
        ++left;
    }

    while (right != endRight)
    {
        result.push_back(*right);
        ++right;
    }

    return result;
}

template <typename T>
void mergesort(std::list<T> &list, typename std::list<T>::iterator start, typename std::list<T>::iterator end)
{
	if (std::distance(start, end) > 1)
	{
		typename std::list<T>::iterator middle = start;
		std::advance(middle, std::distance(start, end) / 2);
		mergesort(list, start, middle);
		mergesort(list, middle, end);
		std::list<T> result = mergeList<T>(start, middle, end);
		std::copy(result.begin(), result.end(), start);
	}
}

void SortDeez::sort(void)
{
	std::cout << "Numbers: ";
	for (size_t i = 0; i < m_vector.size(); i++)
	{
		std::cout << m_vector[i] << " ";
	}
	std::cout << std::endl;

	clock_t start = clock();
	int OddOne;
	if (m_vector.size() % 2 == 0)
		OddOne = -1;
	else
	{
		OddOne = m_list.back();
		m_list.pop_back();
		m_vector.pop_back();
	}
	mergesort(m_list, m_list.begin(), m_list.end());
	if (OddOne != -1)
	{
		std::list<int>::iterator positionList = std::lower_bound(m_list.begin(), m_list.end(), OddOne);
		m_list.insert(positionList, OddOne);
	}
	clock_t end_l = clock();
	clock_t start_v = clock();
		
	mergeSort(m_vector, 0, m_vector.size() - 1);
	if (OddOne != -1)
	{
		std::vector<int>::iterator positionVector = std::lower_bound(m_vector.begin(), m_vector.end(), OddOne);
		m_vector.insert(positionVector, OddOne);
	}
	clock_t end_v = clock();
	std::cout << "Sorted: ";
	for (size_t i = 0; i < m_vector.size(); i++)
	{
		std::cout << m_vector[i] << " ";
	}
	std::cout << "\nList Time: " << (double)(end_l - start) / CLOCKS_PER_SEC * 1000000 << "us" << std::endl;
	std::cout << "Vector Time: " << (double)(end_v - start_v) / CLOCKS_PER_SEC * 1000000 << "us" << std::endl;
}