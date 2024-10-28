/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_library.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:41:00 by artberna          #+#    #+#             */
/*   Updated: 2024/10/17 14:21:34 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIBRARY_H
# define MY_LIBRARY_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <inttypes.h>
# include <limits.h>
# include <pthread.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>

//  *************************  LIBFT  *************************

int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

size_t	ft_strlen(const char *str);
size_t	ft_strcpy(char *dest, const char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t siz);
size_t	ft_strcat(char *dest, char *src);
size_t	ft_strlcat(char *dest, char *src, size_t n);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_realloc(void *s, int old_size, int new_size);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_no_free(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);

char	*ft_itoa(int n);
int		ft_atoi(const char *s);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//  *************************  LISTES CHAINEES  *************************

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);

int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//  *************************  PRINTF  *************************

int		ft_printf(const char *fmt, ...);
int		ft_putchar_printf(char c, int fd);
int		ft_putstr_printf(char *str, int fd);
int		ft_write_fmt(const char *fmt, va_list ap);
int		ft_putnbr_printf(int n, int fd);
int		ft_putnbrun_printf(unsigned int n, int fd);
int		ft_putnbrbase_printf(unsigned long n, int fd, char c, int interupt);

//  *************************  GET_NEXT_LINE  *************************

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);

#endif