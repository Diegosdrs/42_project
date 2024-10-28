/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:05:50 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:57:23 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str1;
	char	*str2;
	int		i;
	int		j;

	str1 = "Salut mon pote!!!";
	str2 = "Salut mon pote";
	j = 20;
	i = ft_strncmp(str1, str2, j);
	printf("MaF : %d\n", i);
	return (0);
}
*/