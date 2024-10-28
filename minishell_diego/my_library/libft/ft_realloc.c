/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:29:38 by artberna          #+#    #+#             */
/*   Updated: 2024/10/09 11:25:15 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

char	*ft_realloc(void *s, int old_size, int new_size)
{
	char	*ret;

	if (!new_size || new_size <= 0)
		return (free(s), NULL);
	ret = malloc(new_size);
	if (!ret)
		return (free(s), NULL);
	if (s)
	{
		ft_memcpy(ret, s, old_size);
		free(s);
	}
	return (ret);
}
