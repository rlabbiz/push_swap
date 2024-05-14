/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ultis2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:45:58 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 11:22:04 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sort_array(int *nbr, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < len && i + 1 != len)
	{
		if (nbr[i] > nbr[i + 1])
		{
			tmp = nbr[i];
			nbr[i] = nbr[i + 1];
			nbr[i + 1] = tmp;
			ft_sort_array(nbr, len);
		}
		i++;
	}
}

void	ft_push_b(t_list **a, t_list **b, char *str)
{
	t_list	*tmp;

	if ((*a) != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		ft_lstadd_front(b, tmp);
	}
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}
