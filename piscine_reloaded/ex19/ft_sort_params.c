/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:05:51 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/14 16:16:23 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(int ac, char **av)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = 1;
	while (j < ac)
	{
		while (i < ac - 1)
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				temp = av[i + 1];
				av[i + 1] = av[i];
				av[i] = temp;
			}
			i++;
		}
		i = 1;
		j++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	ft_sort_params (ac, av);
	while (i <= ac - 1)
	{
		ft_putstr(av[i]);
		i++;
	}
	return (0);
}
