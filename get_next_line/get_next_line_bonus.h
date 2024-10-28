/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:50:00 by dsindres          #+#    #+#             */
/*   Updated: 2024/06/06 16:50:26 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_read(char *tempbuff, int fd);
char	*good_line(char *tempbuff);
char	*free_buff(char	*tempbuff, char *buffer);
void	*ft_calloc(size_t nmemb, size_t size);
int		is_n(char *buffer);
size_t	ft_strlen(const char *str);
char	*next_line(char	*tempbuff);
char	*ft_strjoin(char *s1, char *s2);

#endif