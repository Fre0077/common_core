/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:04:36 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/19 12:33:40 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i  = 0;
	if (str == 	NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	confront(char *s1, char *s2, int start, int end)
{
	int	i;

	if (start < 0 || (start >= end && end != -1))
		return (-1);
	i = start;
	while ((i < end || end == -1) && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] || s2[i])
			return (0);
	return (1);
}

char	*dupstr(char *str, int start)
{
	char	*ret;
	int		i;

	ret = malloc(ft_strlen(str) + 1 - start);
	i = -1;
	while(str[start])
		ret[++i] = str[start++];
	ret[++i] = '\0';
	return (ret);
}

int	check_in(char **av)
{
	int		fd_in;
	int		nread;
	int		pip[2];
	char	buf[100];

	if (confront(av[1], "here_doc", 0, -1))
	{
		pipe(pip);
		ft_printf("pipe heredoc> ");
		nread = read(0, buf, 99);
		while (confront(buf, av[2], 0, -1) == 0)
		{
			write(pip[1], buf, nread);
			printf("test: %s #\n", buf);
			ft_printf("pipe heredoc> ");
			nread = read(0, buf, 99);
		}
		close(pip[1]);
		if (dup2(pip[0], 0) == -1)
			return (ft_printf("Error\nbad input dup\n"), 0);
		return (0);
	}
	fd_in = open(av[1], O_RDWR);
	if (dup2(fd_in, 0) == -1)
		return (ft_printf("Error\nbad input dup\n"), 0);
	return (fd_in);
}

int	check_out(char **av, int ac)
{
	int		fd_out;

	if (confront(av[1], "here_doc", 0, -1))
	{
		fd_out = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
		return (fd_out);
	}
	fd_out = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	return (fd_out);
}