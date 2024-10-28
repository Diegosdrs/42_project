/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:25:22 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:55:47 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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

	i = 48;
	j = 49;
	k = ft_isdigit(i);
	l = ft_isdigit(j);
	printf ("value k = %d,value l = %d\n", k, l);
	return (0);
}
*/
