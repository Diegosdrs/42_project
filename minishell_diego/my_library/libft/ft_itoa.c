/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:23:34 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:55:51 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

static int	ft_length(long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		length;

	nb = n;
	length = ft_length(nb);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb >= 10 && length > 0)
	{
		length--;
		str[length] = nb % 10 + 48;
		nb /= 10;
	}
	str[length - 1] = nb % 10 + 48;
	return (str);
}

/*
int	main(void)
{
	int		i;
	char	*str;

	i = -22;
	str = ft_itoa(i);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
