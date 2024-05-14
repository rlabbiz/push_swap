/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ultis1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:15:11 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 10:22:32 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

int	ft_check(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != NULL)
	{
		i = 0;
		if ((str[j][i] == '-' || str[j][i] == '+')
			&& (str[j][i + 1] != ' ' && str[j][i + 1] != '\0'))
			i++;
		while (str[j][i] != '\0')
		{
			if (!(str[j][i] >= '0' && str[j][i] <= '9'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
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

void	ft_check_empty(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		ft_error();
}

char	*ft_joing_arg(char **av)
{
	char	*str;

	str = ft_strdup(" ");
	av++;
	while (*av)
	{
		ft_check_empty(*av);
		str = ft_strjoin(str, *av);
		str = ft_strjoin(str, " ");
		av++;
	}
	return (str);
}
