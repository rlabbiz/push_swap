/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ultis2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:34:15 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 11:31:57 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
