/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:12:49 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/21 15:18:11 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		philo_thread;
	int				num_philo;
	int				nbr_eaten;
	int				eating;
	size_t			start;
	size_t			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nbr_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				nbr_must_eat;
	int				dead_for_all;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	dead_mutex;
	int				stop;
}	t_data;

//philosophers.c
int		philosophers(t_data *data);
int		init_philo(t_data *data);
int		init_threads_n_join(t_data *data);
int		init_mutex(t_data *data);

//verif_arg.c
int		verif_arg(int ac, char **av, t_data *data);
int		check_content(char **av);
void	init_struct(int ac, char **av, t_data *data);

//routine.c
void	*routine(void *ptr);
void	just_eat(t_philo *philo);
void	just_think(t_philo *philo);
void	just_dream(t_philo *philo);

//routine_2.c
void	print_action(char *str, t_philo *philo, int num);
size_t	my_time(t_philo *philo);
size_t	just_wait(size_t time_in_ms, t_philo *philo);
int		someone_dead(t_philo *philo);

//philo_checker.c
void	*checker_list(void *ptr);
int		philo_dead(t_data *data);
int		is_dead(t_data *data);
int		all_have_eaten(t_data *data);

//utils.c
int		ft_atoi(char *str);
void	exit_all(t_philo *philo);

#endif