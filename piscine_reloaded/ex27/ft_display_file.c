/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:23 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/16 14:43:41 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(int fd)
{
	char	buffer;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, &buffer, 1);
		if (ret == -1)
			write(2, "Cannot read file.\n", 18);
		if (ret > 0)
			write(1, &buffer, 1);
	}
}
/*

	while (read(fd, &buffer, 1) > 0)
		ft_putchar(buffer);
	if (ret <= 0)
		ft_putstr("Cannot read file.\n");
}
*/

int	main(int ac, char **av)
{
	int	fd;

	if (ac > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	if (ac < 2)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			write(2, "Cannot read file.\n", 18);
			return (1);
		}
		ft_display_file(fd);
		close(fd);
	}
	return (0);
}
