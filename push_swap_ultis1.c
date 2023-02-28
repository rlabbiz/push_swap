/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ultis1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:45:55 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/02/28 12:48:39 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void ft_push_b(t_list **a)
{
	t_list *tmp;
	if ((*a) != NULL)
	{
		tmp = *a;
		// void *nbr = tmp->content;
		*a = (*a)->next;
		free (tmp);
		// tmp = NULL;
		// free(tmp);
		// *a = head_a;
		// ft_lstadd_front(&stack->b, ft_lstnew(nbr));
		// ft_print_lst(stack->b);
	}

}