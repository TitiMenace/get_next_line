/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:40:31 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/13 08:43:52 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_fill_line(char *buffer, int fd, char **remain)
{
	int		read_return;

	read_return = 1;
	while (read_return > 0 && !check_buff(*remain, '\n'))
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return <= 0)
			break ;
		buffer[read_return] = 0;
		*remain = ft_strjoin(*remain, buffer);
	}
	return (ft_strndup(*remain));
}

char	*clean_remain(char *remain)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	if (!remain)
		return (NULL);
	while (remain[i] && remain[i] != '\n')
		i++;
	if (!remain[i] || !remain[i + 1])
		return (free(remain), NULL);
	if (remain[i])
		i++;
	out = malloc(sizeof(char) * (ft_strlen(remain + i) + 1));
	if (!out)
		return (free(remain), NULL);
	j = 0;
	while (remain[i])
	{
		out[j] = remain[i];
		i++;
		j++;
	}
	out[j] = 0;
	return (free(remain), out);
}	

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*remain[1024];

	line = "";
	buffer = "";
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_fill_line(buffer, fd, &remain[fd]);
	remain[fd] = clean_remain(remain[fd]);
	return (free(buffer), line);
}

/*int	main()
{
	int fd;
	int fd2;
	char *str;
	
	fd = open("get_next_line.h", O_RDONLY);
	fd2 = open ("test", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd2);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd2);
	printf("%s", str);
	return (0);
}*/
