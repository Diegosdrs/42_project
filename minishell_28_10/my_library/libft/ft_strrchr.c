/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:18:18 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:57:28 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Salut mon pote !";
	char	*result;
	char	*resultresult;
	int		c;

	c = 'o';
	resultresult = strrchr(str, c);
	result = ft_strrchr(str, c);
	if (result != NULL)
		printf(".%s.     .%s.\n", result, resultresult);
	else
		printf("Caractère non trouvé.\n");
	return (0);
}
*/