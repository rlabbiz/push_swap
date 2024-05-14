/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ultis3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:46:00 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 09:41:56 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **head, char *str)
{
	t_list	*a;
	int		nbr;

	a = *head;
	if (!a || a->next == NULL)
		return ;
	nbr = a->content;
	a->content = a->next->content;
	a->next->content = nbr;
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_swap_all(t_list **a, t_list **b, char *str)
{
	ft_swap(a, NULL);
	ft_swap(b, NULL);
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	ft_get_index(t_list *stack, int value)
{
	t_list	*lst;
	int		index;

	lst = stack;
	index = 0;
	while (lst != NULL && lst->content != value)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

void	ft_free_args(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
}

int	ft_check_int_range(char **str)
{
	int			i;
	int			j;
	long long	nbr;

	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		while (str[i][j] != '\0' && (str[i][j] == ' ' || str[i][j] == '0'))
			j++;
		if (ft_strlen(str[i] + j) > 10)
			ft_error();
		else
		{
			nbr = ft_atol(str[i]);
			if (nbr < INT_MIN || nbr > INT_MAX)
				ft_error();
		}
		i++;
	}
	return (1);
}
