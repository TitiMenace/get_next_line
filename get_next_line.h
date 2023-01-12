/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:09:52 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/12 02:17:48 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* -------------------------------------------------------------------------- */
/*                       FILE = ./get_next_line_utils.c                       */
/* -------------------------------------------------------------------------- */
int		ft_strlen(char *str);
char	*ft_strndup(char *str);
int		check_buff(char *buffer, char c);
char	*ft_strjoin(char *remain, char *buffer);

/* -------------------------------------------------------------------------- */
/*                          FILE = ./get_next_line.c                          */
/* -------------------------------------------------------------------------- */
char	*ft_fill_line(char *buffer, int fd, char **remain);
char	*clean_remain(char *remain);
char	*get_next_line(int fd);


#endif
