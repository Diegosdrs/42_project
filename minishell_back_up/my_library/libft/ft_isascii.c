/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:41:00 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:55:44 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	j = 128;
	k = ft_isascii(i);
	l = ft_isascii(j);
	printf ("value k = %d,value l = %d\n", k, l);
	return (0);
}
*/