/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:16:26 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/22 15:40:30 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_data
{
	const char	*s;
	va_list		ap;
	int			chars_written;
	char		*base16;
}	t_data;

//pipex.c
void	first_command(char **av, int *fd, char **envp);
void	second_command(char **av, int *fd, char **envp);

//utils.c
void	ft_error(void);
void	ft_free(char **str);
void	do_command(char *cmd, char **envp);
void	do_command_2(char **command, char **envp);
char	*find_command(char *command, char **envp);
void	ft_putstr_fd(char *s, int fd);
int		check_command(char **av);
int		check_command_2(char **av);

//ft_printf.c
int		init_data(t_data *data, const char *str);
int		ft_printf(const char *str, ...);
int		parsing_str(t_data *data);
void	printchar(char c, t_data *data);
int		print_str(char *s, t_data *data);
void	print_pointer(unsigned long n, t_data *data, int interupt);
int		print_numbers(long n, int base, t_data *data);

//fontions utiles
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *str);

#endif
