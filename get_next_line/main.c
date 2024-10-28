/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:01:19 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/25 11:51:47 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/* static int	ft_is_sep(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;
	int		len;

	if (!set || !s1)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_is_sep(s1[start], set))
		start++;
	while (s1[end] && ft_is_sep(s1[end], set))
		end--;
	len = end - start + 1;
	if (len < 0)
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
 */
/* static void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int     main(void)
{
	int	fd;
	char	**str;
	int	i;
	char	*line;
	
	str = ft_calloc(100, sizeof(char *));
	i = 0;
	fd = open ("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line != NULL)
	{
		str[i] = line;
		line = get_next_line(fd);
		printf("%s\n", str[i]);
		i++;
	}
	str[i] = NULL;
	free_double(str);
	close (fd);
	return(0);
} */

int     main(void)
{
	int	fd;
	char	*str;
	int	i;
	
	i = 0;
	fd = open ("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	close (fd);
	free(str);
	return(0);
}