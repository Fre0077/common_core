/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:28 by fde-sant          #+#    #+#             */
/*   Updated: 2024/11/30 15:32:40 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*temp_copy(char **buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!(*buffer))
		return (NULL);
	while ((*buffer)[i])
		i++;
	str = malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	i = -1;
	while ((*buffer)[++i])
		str[i] = (*buffer)[i];
	free((*buffer));
	return (str);
}

char	*get_next_line_one(int fd, char **buffer)
{
	char			*join;
	char			*temp;
	int				read_return;

	if ((*buffer) != NULL && check_buffer(buffer, 0) == 0)
		return (return_buffer(buffer));
	join = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_return = read(fd, join, BUFFER_SIZE);
	join[read_return] = '\0';
	if (read_return > 0)
	{
		temp = temp_copy(buffer);
		(*buffer) = malloc(sizeof(char) * buffer_size(temp, join));
		join_buffer(buffer, temp, join);
		if (check_buffer(buffer, read_return) == 1)
			return (get_next_line_one(fd, buffer));
	}
	if (read_return == 0)
		free (join);
	return (return_buffer(buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];

	return (get_next_line_one(fd, &buffer[fd]));
}

/* int main()
{
	int fd = open("papere", O_RDONLY);
	int fd1 = open("papere_blu", O_RDONLY);
	int fd2 = open("papere_rosse", O_RDONLY);
	char	*str;

	str = get_next_line(fd);
	printf("%s.\n\n\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("%s.\n\n\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("%s.\n\n\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s.\n\n\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("%s.\n\n\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("%s.\n\n\n", str);
	free(str);
	close(fd);
	return (0);
} */