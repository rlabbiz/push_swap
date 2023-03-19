/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:08:52 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 11:37:30 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"
# include "limits.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

typedef struct s_push
{
	t_list	*a;
	t_list	*b;
}	t_push;

typedef struct s_sort
{
	int	start;
	int	end;
	int	i;
	int	*nbr;
}	t_sort;

void		ft_error(void);
int			ft_check(char **str);
void		ft_swap(t_list **head, char *str);
void		ft_print_lst(t_list *head);
void		ft_push_b(t_list **a, t_list **b, char *str);
void		ft_push_a(t_list **a, t_list **b, char *str);
void		ft_rotate(t_list **head, char *str);
void		ft_rrotate(t_list **head, char *str);
void		ft_rotate_all(t_list **a, t_list **b, char *str);
void		ft_rrotate_all(t_list **a, t_list **b, char *str);
void		ft_swap_all(t_list **a, t_list **b, char *str);
char		*get_next_line(int fd);
void		ft_check_empty(char *str);
char		*ft_joing_arg(char **av);
int			ft_store(char **str, t_push *stack, int **nbr);
int			ft_get_index(t_list *stack, int value);
int			ft_check_content(int a, int b);
int			ft_check_sort(int **nbr, int len);
long long	ft_atol(char *str);
void		ft_free_args(char **str);
int			ft_check_int_range(char **str);
void		ft_free_stack(t_list **a, t_list **b);

#endif
