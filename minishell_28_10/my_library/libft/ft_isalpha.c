/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:54:51 by artberna          #+#    #+#             */
/*   Updated: 2024/06/18 09:55:41 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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

	i = 050;
	j = 124;
	k = ft_isalpha(i);
	l = ft_isalpha(j);
	printf ("value k = %d,value l = %d\n", k, l);
	return (0);
}
*/
