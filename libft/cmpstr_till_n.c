/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpstr_till_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:51:58 by fre007            #+#    #+#             */
/*   Updated: 2025/01/29 09:59:00 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//compara i primi n caratteri delle stringhe
int	cmpstr_till_n(char *str1, char *str2, int n)
{
	if (n < 0)
		return (0);
	if (str1 == NULL && str2 == NULL)
		return (1);
	else if (str1 == NULL || str2 == NULL)
		return (0);
	if (ft_strlen(str1) < n || ft_strlen(str2) < n)
		return (0);
	while (--n >= 0)
		if (str1[n] != str2[n])
			return (0);
	return (1);
}