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

char	*ft_get_rest(char *rest, char *buffer, char *out)
{	
	char	*temp;
	int	i;
	int	j;

	temp = ft_strjoin(rest, buffer);
	i = 0;
	while (temp[i] == out[i])
		i++;
	j = i;
	while(temp[j])
		j++;
	free(rest);
	rest = malloc(sizeof(char) * j + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while(temp[i])
	{
		rest[j] = temp[i];
		j++;
		i++;
	}
	rest[j] = '\0';
	return (free(temp), rest);
}

char	*ft_new_line(char *buffer, char *rest)
{
	int		i;
	char	*out;

	i = 0;
	while (rest[i - 1] != '\n' && rest[i])
		i++;
	if (rest[i - 1] == '\n' || (rest[i] == '\0' && !buffer))
	{
		out = ft_nlncpy(rest, i);
		return (out);
	}
	else
		out = ft_nljoin(rest, buffer);
		return (out);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*out;
	static char	*rest;
	
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (!rest)
		rest = "";
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	out = ft_new_line(buffer, rest);
	rest = ft_get_rest(rest, buffer, out); 
	return (free(buffer), out);
}

#include <stdio.h>

int	main()
{
	char	*str;
	int	fd;

	fd = open("get_next_line.h", O_RDONLY);
	if (fd < 0)
		return (printf("error\n"));
	str = get_next_line(fd);
	printf("%s\n", str);
}



















