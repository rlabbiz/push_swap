/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:25:46 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 11:21:07 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_sort(int **nbr, int len)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < len && i + 1 < len)
	{
		if ((*nbr)[i] > (*nbr)[i + 1])
		{
			check = 1;
			break ;
		}
		i++;
	}
	return (check);
}

static void	ft_store_small(char **str, int **nbr, int i, int len)
{
	int	j;

	j = 0;
	while (str[i] != NULL)
	{
		(*nbr)[i] = ft_atoi(str[i]);
		i++;
	}
	i = len - 1;
	while (i >= 0)
	{
		j = i + 1;
		while (j < len)
		{
			if ((*nbr)[i] == (*nbr)[j])
				ft_error();
			j++;
		}
		i--;
	}
	if (ft_check_sort(nbr, len) == 0)
	{
		free((*nbr));
		exit(0);
	}
}

int	ft_store(char **str, t_push *stack, int **nbr)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[len] != NULL)
		len++;
	(*nbr) = (int *)malloc(sizeof(int ) * len);
	ft_store_small(str, nbr, i, len);
	i = len - 1;
	while (i >= 0)
	{
		ft_lstadd_front(&stack->a, ft_lstnew((*nbr)[i]));
		i--;
	}
	return (len);
}

int	ft_check_content(int a, int b)
{
	if (a <= b)
		return (1);
	return (0);
}

int	ft_get_index(t_list *stack, int value)
{
	t_list	*lst;
	int		index;

	index = 0;
	lst = stack;
	while (lst != NULL && lst->content != value)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}
