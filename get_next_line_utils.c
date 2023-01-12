/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:06:21 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/12 06:42:09 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *str)
{
	int		i;
	char	*out;

	i = 0;
	if (!str)
		return (NULL);
	out = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (str[i])
	{
		out[i] = str[i];
		i++;
		if (out[i - 1] == '\n')
			break ;
	}
	out[i] = 0;
	return (out);
}

int	check_buff(char *buffer, char c)
{
	int	len;

	len = 0;
	if (!buffer)
		return (0);
	while (buffer[len])
	{
		if (buffer[len] == c)
			return (1);
		len++;
	}
	return (0);
}

char	*ft_strjoin(char *remain, char *buffer)
{
	char	*new_line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!remain)
		remain = ft_strndup("\0");
	if (!buffer)
		return (NULL);
	new_line = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(remain) + 1));
	if (!new_line)
		return (NULL);
	while (remain[i])
	{
		new_line[i] = remain[i];
		i++;
	}
	while (buffer[j])
	{
		new_line[i + j] = buffer[j];
		j++;
	}
	new_line[i + j] = 0;
	return (free(remain), new_line);
}
