/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:21:20 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/14 16:29:33 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar('N');
	}
	else
		ft_putchar('P');
}
/*
int	main (void)
{
	int	i;
	int	j;
	int	k;

	i = 12;
	j = 0;
	k = -5;
	ft_is_negative(i);
	ft_is_negative(j);
	ft_is_negative(k);
	return (0);
}*/
