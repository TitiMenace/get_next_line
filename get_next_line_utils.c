/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:40:43 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/25 04:40:04 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_nlncpy(char *src, int n)
{
	int	i;
	char	*out;

	out = malloc(sizeof(char) * n + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		out[i] = src[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

int	ft_nljoinlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i - 1] != '\n')
		i++;
	return (i);
}

char	*ft_nljoin(char *s1, char *s2)
{
	 char	*out;
	 int	i;
	 int	j;

	 out = malloc(sizeof(char) * (ft_nljoinlen(s1) + ft_nljoinlen(s2)) + 1);
	 if (!out)
		 return (NULL);
	 i = 0;
	 while (s1[i])
	 {
		out[i] = s1[i];
		i++;
	 }
	 j = 0;
	 while (s2[j] && s2[j - 1] != '\n')
	 {
		out[i] = s2[j];
		j++;
		i++;
	 }
	 out[i] = '\0';
	 return (out);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	int	i;
	int	j;

	out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		out[i] = s2[j];
		i++;
		j++;
	}
	out[i] = '\0';
	return (out);
}
