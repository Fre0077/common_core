/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:22:58 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/19 11:56:23 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

char	**ft_split_add(char *str, char *add, char c);
char	*dupstr(char *str, int start);
int		ft_printf(const char *n, ...);
int		confront(char *s1, char *s2, int start, int end);
int		check_in(char **av);
int		check_out(char **av, int ac);




#endif
