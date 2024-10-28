/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:12:23 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/14 14:37:47 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}
/*
int	f(char c)
{

	if (c == 97)
			
		return (1);
	else
		return (0);
}

int	main(void)
{
	char	tab = {"falshaaajfs", "afefwfrg"};
	printf("%d", ft_count_if(tab, &f));
	return (0);
}*/
