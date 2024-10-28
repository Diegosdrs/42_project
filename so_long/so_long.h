/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:37:05 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/07 11:11:30 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <string.h>
# include <sys/wait.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define HEIGHT 64
# define WIDTH 64

typedef struct s_long
{
	int		x;
	int		y;
	int		p;
	int		e;
	int		c;
	void	*mlx_connection;
	void	*window;
	void	*img_back;
	void	*img_wall;
	void	*img_coll;
	void	*img_exit;
	void	*img_player;
	char	*path_back;
	char	*path_wall;
	char	*path_coll;
	char	*path_exit;
	char	*path_player;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	char	**map;
}	t_long;

//Verification file et parsing

//check_file.c
char	**check_file(char	*file, t_long *data);
int		check_ber(char *file);
char	**display_map(char *file);
char	**display_map_2(char **map, char *file, int data);
int		check_map(char **map, t_long *data);
//check_file_2.c
int		is_it_square(char **map, t_long *data);
int		is_it_square_2(char **map, t_long *data);
int		check_line(char **map, t_long *data);
int		middle_line(char **map, t_long *data);
int		last_line(char **map, t_long *data);
//check_file_3.c
int		check_symbol(char **map, t_long *data);
int		floodfill(char **map, t_long *data);
int		dfs(char **map_copy, int y, int x, t_long *data);
void	find_p(char **map, t_long *P);
//check_file_4.c
char	**create_copy(char **map, t_long *data);
char	**create_copy_2(char **map, char **map_copy);
int		good_floodfill(char **map, char **map_copy);
//utils.c
void	free_double(char **str);
void	print_double(char **str);
void	error_fd(void);
void	error_fd_2(int fd);
void	error_fd_3(char **map, int i);

//Partie graphique

//game.c
int		game_controler(t_long *data);
int		display_window(t_long *data);
int		init_image(t_long *data);
void	init_ptr_img(t_long *data);
//key_input.c
int		key_input(int keysym, t_long *data);
int		move_up(t_long *data, t_long *player);
int		move_left(t_long *data, t_long *player);
int		move_down(t_long *data, t_long *player);
int		move_right(t_long *data, t_long *player);
//close_game.c
int		close_window(t_long *data);
void	escape(t_long *data);
void	you_win(t_long *data, int count_input);
void	free_all(t_long *data);
//display_image.c
int		display_image(t_long *data);
int		display_structure(t_long *data);
int		display_others(t_long *data);

#endif