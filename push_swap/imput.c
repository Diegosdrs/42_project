/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:11:25 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/09 11:05:41 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_imput(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		if ((str[j][0] == 43 && str[j][1] >= 48 && str[j][1] <= 57)
			|| (str[j][0] == 45 && str[j][1] >= 48 && str[j][1] <= 57))
			i++;
		while (str[j][i])
		{
			if (str[j][i] >= 48 && str[j][i] <= 57)
				i++;
			else
				return (1);
		}
		j++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	len_dest;

	len_dest = ft_strlen(dest);
	i = 0;
	{
		while (src[i] != '\0')
		{
			dest[len_dest + i] = src[i];
			i++;
		}
		dest[len_dest + i] = '\0';
	}
	return ;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	if (nmemb != 0 && size != 0 && (SIZE_MAX / nmemb) < size)
		return (NULL);
	tab = (unsigned char *) malloc (nmemb * size);
	if (tab == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

char	*parsing(int ac, char **av)
{
	int		i;
	int		total_len;
	char	*str;

	total_len = 0;
	i = 1;
	while (i < ac)
	{
		total_len += ft_strlen(av[i]);
		i++;
	}
	total_len += (ac - 2);
	i = 1;
	str = ft_calloc(total_len + 1, sizeof(char));
	while (i < ac)
	{
		ft_strcat(str, av[i]);
		if (i != (ac - 1))
			ft_strcat(str, " ");
		i++;
	}
	return (str);
}
