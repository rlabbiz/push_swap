/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:15:06 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 13:36:13 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_s(t_list **a, t_list **b, t_sort *sort, int len)
{
	ft_push_b(a, b, "pb");
	ft_rotate(b, "rb");
	if (sort->end < len)
	{
		sort->start++;
		sort->end++;
	}
}

static void	ft_sort_small(t_list **a, t_list **b, t_sort *sort, int len)
{
	while (sort->i < len)
	{
		if ((*a)->content == sort->nbr[sort->i])
		{
			if (sort->i >= sort->start && sort->i <= sort->end)
			{
				ft_push_b(a, b, "pb");
				if (sort->end < len)
				{
					sort->start++;
					sort->end++;
				}
			}
			else if (sort->i < sort->start)
				ft_sort_s(a, b, sort, len);
			else if (sort->i > sort->end)
				ft_rotate(a, "ra");
			break ;
		}
		sort->i++;
	}
}

void	ft_sort(t_list **a, t_list **b, int *nbr, int len)
{
	t_sort	sort;

	sort.i = 0;
	sort.start = 0;
	sort.end = 15;
	sort.nbr = nbr;
	if (len > 150)
		sort.end = 35;
	while ((*a) != NULL)
	{
		sort.i = 0;
		ft_sort_small(a, b, &sort, len);
	}
}

void	ft_final_sort(t_list **a, t_list **b, int len, int *nbr)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while ((*b) != NULL)
	{
		index = ft_get_index(*b, nbr[len - i]);
		if (index > 0 && index <= (len - i) / 2)
		{
			while ((*b)->content != nbr[len - i])
				ft_rotate(b, "rb");
		}
		else if (index > 0 && index > (len - i) / 2)
		{
			index = (len - 1) - index;
			while ((*b)->content != nbr[len - i])
				ft_rrotate(b, "rrb");
		}
		ft_push_a(a, b, "pa");
		i++;
	}
}

long long	ft_atol(char *str)
{
	int			i;
	long long	c;
	long long	result;

	i = 0;
	c = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		c = -1;
		i++;
	}
	if (ft_strlen(str + i) > 10)
		ft_error();
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * c);
}
