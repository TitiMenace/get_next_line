/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:41:05 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/25 04:42:31 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_new_line(char *buffer, char *rest);
char	*ft_get_rest(char *rest, char *buffer, char *out);
char	*ft_nlncpy(char *src, int n);
char	*ft_nljoin(char *s1, char *s2);
int	ft_nljoinlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *str);

#endif
