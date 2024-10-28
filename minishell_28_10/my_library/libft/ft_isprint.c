/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:47:36 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:55:49 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
	k = ft_isprint(i);
	l = ft_isprint(j);
	printf ("value k = %d,value l = %d\n", k, l);
	return (0);
}
*/
