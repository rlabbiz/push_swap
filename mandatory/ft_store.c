/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:10:12 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 09:27:40 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (1);
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
