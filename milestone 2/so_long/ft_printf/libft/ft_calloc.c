/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:57:14 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/08 11:04:23 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calloc(int len)
{
	char	*str;
	int		i;

	str = malloc(len);
	i = -1;
	while (++i < len)
		str[i] = '\0';
	return (str);
}

/* int main()
{
	size_t nmemb = 5;
	size_t size = sizeof(int);

	int *arr_original = (int *)calloc(nmemb, size);
	int *arr_comparato = (int *)ft_calloc(nmemb, size);

	for (size_t i = 0; i < nmemb; i++) {
		printf;
	}

	free(arr_original);
	free(arr_comparato);

	return 0;
} */