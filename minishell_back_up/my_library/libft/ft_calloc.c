/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:27:31 by artberna          #+#    #+#             */
/*   Updated: 2024/06/20 15:22:19 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	if (size != 0 && nmemb != 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	str = (unsigned char *) malloc (nmemb * size);
	if (!str)
		return (NULL);
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

/*
#include <stdio.h>

void	test_calloc(size_t nmemb, size_t size)
{
	void *ptr_std, *ptr_ft;
	size_t i;
	int success = 1;

	// Utiliser calloc
	ptr_std = calloc(nmemb, size);
	// Utiliser ft_calloc
	ptr_ft = ft_calloc(nmemb, size);

	// Comparer les deux résultats
	if (!ptr_std || !ptr_ft) {
		printf("Allocation failed for size %zu * %zu\n", nmemb, size);
	} else {
		for (i = 0; i < nmemb * size; i++) {
			if (((unsigned char *)ptr_std)[i] != ((unsigned char *)ptr_ft)[i]) {
				success = 0;
				break;
			}
		}
		if (success) {
			printf("Test passed for size %zu * %zu\n", nmemb, size);
		} else {
			printf("Test failed for size %zu * %zu\n", nmemb, size);
		}
	}

	// Libérer la mémoire
	free(ptr_std);
	free(ptr_ft);
}

int	main(void)
{
	// Test cases
	test_calloc(5, sizeof(char));
	test_calloc(10, sizeof(int));
	test_calloc(20, sizeof(double));
	test_calloc(0, sizeof(int));
	test_calloc(5, 0);

	return 0;
}
*/