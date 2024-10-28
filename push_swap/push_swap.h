/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:17:13 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/11 14:14:33 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				price;
	int				mediane;
	int				position;
	int				cheap;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

size_t	ft_strlen(const char *str);
void	ft_strcat(char *dest, char *src);
void	*ft_calloc(size_t nmemb, size_t size);
char	*parsing(int ac, char **av);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		valid_imput(char **str);
int		push_swap(int ac, char **av, t_list **li, t_list **lib);
long	ft_atolong(const char *str);
int		create_list(char **str, t_list **li);
void	init_list(int value, t_list **li);
void	print_list(t_list **li);
int		checkdouble(int value, t_list *li);
void	free_lst(t_list *li);
char	**manage_imput(int ac, char **av);
int		manage_list(char **str, t_list **li);
int		algo_tri(t_list **a, t_list **b);
void	sa(t_list **li);
void	sb(t_list **li);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
t_list	*last_li(t_list *li);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
int		in_order(t_list **a);
int		li_size(t_list *li);

void	insertion(t_list **a, int len);
void	insertion_order(t_list **a, t_list **b, int len);
void	moove_rra(t_list **a, t_list **b, int i, int len);
void	moove_ra(t_list **a, t_list **b, int i);
void	put_in_order(t_list **a, int len);
void	put_in_order2(t_list **a, int len, int i);
int		is_it_croissant2(t_list **a, t_list *min);
int		is_it_croissant(t_list **a);
t_list	*find_max(t_list **a);
t_list	*find_min(t_list *a);
void	algo_for_3(t_list **a);
void	algo_for_5(t_list **a, t_list **b, int len);
void	push_min(t_list **a, t_list **b, t_list *min);

void	big_algo(t_list **a, t_list **b, int len);
void	init_big_algo_0(t_list *li);
void	init_big_algo(t_list *a, t_list *b);
void	target(t_list *a, t_list *b);
void	quid_mediane(t_list *li);
void	position(t_list *a);
void	exec_algo(t_list **a, t_list **b);
void	big_algo_1(t_list **a, t_list **b, t_list *cheap);
void	big_algo_2(t_list **a, t_list **b, t_list *cheap);
void	big_algo_3(t_list **a, t_list **b, t_list *cheap);
void	big_algo_4(t_list **a, t_list **b, t_list *cheap);
int		real_position(t_list **li, t_list *pointeur);
t_list	*find_cheapest(t_list **b);
void	price(t_list *b, int len_a, int len_b);
void	price_med_0(t_list *b, int len_b);
void	price_med_1(t_list *b, int len_a, int len_b);

typedef struct s_data
{
	const char	*s;
	va_list		ap;
	int			chars_written;
	char		*base16;
}	t_data;

int		ft_printf(const char *str, ...);
void	printchar(char c, t_data *data);
int		init_data(t_data *data, const char *str);
int		parsing_str(t_data *data);
int		print_str(char *s, t_data *data);
int		print_numbers(long n, int base, t_data *data);
void	print_pointer(unsigned long n, t_data *data, int interupt);

void	rotate_both(t_list **a, t_list **b, t_list *cheap);
void	reverse_rotate_both(t_list **a, t_list **b, t_list *cheap);
void	finish_rotation(t_list **list, t_list *top_node, char list_name);
void	set_current_position(t_list *stack);
t_list	*return_cheapest(t_list *stack);

#endif