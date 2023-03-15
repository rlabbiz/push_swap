/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:10:12 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/14 22:37:03 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error(void)
{
	printf("Error\n");
	exit(1);
}

int ft_check(char **str)
{
	int	i = 0;
	int j = 0;

	while (str[j] != NULL)
	{
		i = 0;
		if ((str[j][i] == '-' || str[j][i] == '+') && (str[j][i + 1] != ' ' && str[j][i + 1] != '\0'))
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
