/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:03:36 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/11 20:42:35 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_arr_split(char const *arr, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (arr[x] != '\0')
	{
		if ((arr[x] == c && arr[x + 1] != c && arr[x + 1] != '\0') || \
		(x == 0 && arr[x] != c))
			i++;
		x++;
	}
	return (i);
}

static void	frite(char *dest, int i, int conta, char const *s)
{
	int	g;

	g = 0;
	while (g + i < i + conta)
	{
		dest[g] = s[i + (g)];
		g++;
	}
	dest[g] = '\0';
}

static char	**fill(char **dest, char c, char const *s, int len_arr)
{
	int	i;
	int	x;
	int	y;
	int	conta;

	i = 0;
	x = 0;
	y = 0;
	while (x < len_arr)
	{
		conta = 1;
		while (s[i++] == c)
			;
		y = i;
		while (s[y] != '\0' && s[y++] != c)
			conta++;
		dest[x] = (char *) malloc(sizeof(char) * (conta + 1));
		if (dest[x] == NULL)
			return (NULL);
		frite(dest[x++], i - 1, conta, s);
		while (s[y] != '\0' && s[i++] != c)
			;
	}
	dest[x] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		x;
	int		len_arr;
	char	**dest;

	x = 0;
	len_arr = len_arr_split(s, c);
	dest = (char **) malloc(sizeof(char *) * (len_arr + 1));
	if (dest == NULL)
		return (NULL);
	if (fill(dest, c, s, len_arr) == NULL)
	{
		while (x ++ <= len_arr)
			free(dest[x]);
		return (NULL);
	}
	return (dest);
}