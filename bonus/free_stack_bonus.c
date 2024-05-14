/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:36:58 by rlabbiz           #+#    #+#             */
/*   Updated: 2024/05/14 19:23:48 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_free_stack(t_list **a, t_list **b)
{
	t_list	*tmp;

	while ((*a) != NULL)
	{
		tmp = (*a)->next;
		free((*a));
		(*a) = tmp;
	}
	while ((*b) != NULL)
	{
		tmp = (*b)->next;
		free((*b));
		(*b) = tmp;
	}
}
