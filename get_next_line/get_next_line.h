/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:35:24 by dsindres          #+#    #+#             */
/*   Updated: 2024/09/14 13:28:18 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_read(char *tempbuff, int fd);
char	*good_line(char *tempbuff);
char	*free_buff(char	*tempbuff, char *buffer);
void	*ft_calloc(size_t nmemb, size_t size);
//int		is_n(char *buffer);
size_t	ft_strlen(const char *str);
char	*next_line(char	*tempbuff);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);


#endif