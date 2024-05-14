/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:27:16 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 11:36:34 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
