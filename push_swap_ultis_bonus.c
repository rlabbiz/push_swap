/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ultis_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:10:23 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 10:24:16 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push_a(t_list **a, t_list **b, char *str)
{
	t_list	*tmp;

	if ((*b) != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		ft_lstadd_front(a, tmp);
	}
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_rotate(t_list **head, char *str)
{
	t_list	*tmp;
	t_list	*new_head;

	if ((*head) == NULL)
		return ;
	tmp = *head;
	new_head = (*head)->next;
	while ((*head)->next != NULL)
	{
		(*head) = (*head)->next;
	}
	(*head)->next = tmp;
	tmp->next = NULL;
	(*head) = new_head;
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_rotate_all(t_list **a, t_list **b, char *str)
{
	ft_rotate(a, NULL);
	ft_rotate(b, NULL);
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_rrotate(t_list **head, char *str)
{
	t_list	*tmp;
	t_list	*new_last;

	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	while ((*head)->next != NULL)
	{
		new_last = (*head);
		(*head) = (*head)->next;
	}
	(*head)->next = tmp;
	new_last->next = NULL;
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_rrotate_all(t_list **a, t_list **b, char *str)
{
	ft_rrotate(a, NULL);
	ft_rrotate(b, NULL);
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}
