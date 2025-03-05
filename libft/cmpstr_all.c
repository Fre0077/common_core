/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpstr_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:31:01 by fre007            #+#    #+#             */
/*   Updated: 2025/01/29 09:50:14 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//compara le stringhe controllando che siano perfettamente identicche
int	cmpstr_all(char *str1, char *str2)
{
	int	i;

	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	if (str1 == NULL && str2 == NULL)
		return (1);
	i = -1;
	while (str1[++i])
		if (str1[i] != str2[i])
			return (0);
	return (1);
}