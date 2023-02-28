/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:10:34 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/02/28 12:22:16 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_push
{
	t_list	*a;
	t_list	*b;
}	t_push;

// void	ft_store(char **av, t_push *stack);
void	ft_error(void);
int		ft_check(char **str);
void	ft_swap(t_list **head, int c);
void	ft_print_lst(t_list *head);
void	ft_push_b(t_list **a);


#endif
