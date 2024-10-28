/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:41:22 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/22 17:25:57 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

static int	ft_len(long n)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (n < 0)
	{
		n = -n;
		j = 1;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + j);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	nbr = n;
	len = ft_len(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr >= 10 && len > 0)
	{
		len--;
		str[len] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	str[len - 1] = nbr % 10 + 48;
	return (str);
}
/*
int	main(void)
{
	char	*str;

	str = ft_itoa(0);
	printf("%s", str);
	return (0);
}*/
