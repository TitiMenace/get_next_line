/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:37:18 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/25 05:09:11 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*temp;
	char	*out;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	temp = buffer;
	while (*buffer != '\n' && *buffer)
		buffer++;
	if (*buffer == '\0')
	{
		out = ft_strdup(temp);
		return (out);
	}
	if (*buffer == '\n')
	{
		out = malloc(sizeof(char) * get_new_line_len(temp) + 1);
		if (!out)
			return (NULL);
		*buffer = '\0';
		out = ft_new_line_cpy(out, temp);
		return (out);
	}
	return (NULL);
}

int	main()
{
	char	*str;
	int	fd;

	fd = open("get_next_line.h", O_RDONLY);
	if (fd < 0)
		return (-1);
	str = get_next_line(fd);
	write (1, str, BUFFER_SIZE);
	str = get_next_line(fd);
	write (1, str, BUFFER_SIZE);
	return (0);
}
