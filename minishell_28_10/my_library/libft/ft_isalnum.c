/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:34:32 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:55:39 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 120;
	j = 8;
	k = ft_isalnum(i);
	l = ft_isalnum(j);
	printf ("value k = %d,value l = %d\n", k, l);
	return (0);
}
*/
