/* #include "get_next_line.h"

char	*check(char *storage, int fd)
{
	int		i;
	char	*let;

	i = 0;
	if (storage)
	{
		i = -1;
		if (storage[0] == '\0')
			return (NULL);
		let = malloc(sizeof(char) * (ft_strlen(storage) + 1));
		while (storage[++i])
			let[i] = storage[i];
		let[i] = '\0';
	}
	else if (storage == NULL)
	{
		let = malloc(BUFFER_SIZE + 1);
		if (!let)
			return (NULL);
		let[BUFFER_SIZE] = '\0';
		read(fd, let, BUFFER_SIZE);
	}
	return (let);
}

char	*str_creation(char *let, int *k)
{
	char	*str;
	int		i;

	i = 0;
	while (let[i] != '\n' && let[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	str[i + 1] = '\0';
	i = 0;
	while (let[i] && let[i] != '\n')
	{
		str[i] = let[i];
		i++;
	}
	str[i] = let[i];
	*k = i;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*str;
	char		*let;
	int			i;
	int			k;

	let = check(storage, fd);
	if (!let)
		return (NULL);
	str = str_creation(let, &i);
	free(storage);
	printf("k:%d\ni:%d\n\n", ft_strlen(let) - i, i);
	if ((ft_strlen(let) - i) != 0)
	{
		storage = malloc(sizeof(char) * (ft_strlen(let) - i));
		storage[ft_strlen(let) - i - 1] = '\0';
		i++;
	}
	else
	{
		storage = malloc(sizeof(char) * 1);
		storage[0] = '\0';
	}
	k = 0;
	while (let[i])
		storage[k++] = let[i++];
	free(let);
	return (str);
}

int main()
{
	int fd = open("papere_secche", O_RDONLY);
	char	*str;

	str = get_next_line(fd);
	printf("TEST 1:\n%s.\n\n", str);
	free(str);
	str = get_next_line(fd);
	printf("TEST 2:\n%s.\n\n", str);
	free(str);
	str = get_next_line(fd);
	printf("TEST 3:\n%s.\n\n", str);
	free(str);
	str = get_next_line(fd);
	printf("TEST 4:\n%s.\n\n", str);
	free(str);
	str = get_next_line(fd);
	printf("TEST 5:\n%s.\n\n", str);
	free(str);
	str = get_next_line(fd);
	printf("TEST 6:\n%s.\n\n", str);
	free(str);
	close(fd);
} */