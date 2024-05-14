/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:09:44 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 12:05:36 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_if_sort(t_list **a, t_list **b)
{
	if ((*b) != NULL)
	{
		ft_putstr_fd("KO\n", 1);
		exit(0);
	}
	while ((*a)->next != NULL)
	{
		if ((*a)->content > (*a)->next->content)
		{
			ft_putstr_fd("KO\n", 1);
			exit(0);
		}
		(*a) = (*a)->next;
	}
	ft_putstr_fd("OK\n", 1);
}

int	ft_apply_small(t_list **a, t_list **b, char *str)
{
	if (ft_strlen(str) - 1 == 2 && ft_strncmp(str, "sa", 2) == 0)
		ft_swap(a, NULL);
	else if (ft_strlen(str) - 1 == 2 && ft_strncmp(str, "sb", 2) == 0)
		ft_swap(b, NULL);
	else if (ft_strlen(str) - 1 == 2 && ft_strncmp(str, "ra", 2) == 0)
		ft_rotate(a, NULL);
	else if (ft_strlen(str) - 1 == 2 && ft_strncmp(str, "rb", 2) == 0)
		ft_rotate(b, NULL);
	else if (ft_strlen(str) - 1 == 2 && ft_strncmp(str, "pa", 2) == 0)
		ft_push_a(a, b, NULL);
	else if (ft_strlen(str) - 1 == 2 && ft_strncmp(str, "pb", 2) == 0)
		ft_push_b(a, b, NULL);
	else if (ft_strlen(str) - 1 == 3 && ft_strncmp(str, "rra", 3) == 0)
		ft_rrotate(a, NULL);
	else if (ft_strlen(str) - 1 == 3 && ft_strncmp(str, "rrb", 3) == 0)
		ft_rrotate(b, NULL);
	else if (ft_strlen(str) - 1 == 2 && ft_strncmp(str, "ss", 2) == 0)
		ft_swap_all(a, b, NULL);
	else if (ft_strlen(str) - 1 == 2 && ft_strncmp(str, "rr", 2) == 0)
		ft_rotate_all(a, b, NULL);
	else if (ft_strlen(str) - 1 == 3 && ft_strncmp(str, "rrr", 3) == 0)
		ft_rrotate_all(a, b, NULL);
	else
		return (1);
	return (0);
}

void	ft_apply(t_list **a, t_list **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (ft_apply_small(a, b, str) == 1)
		{
			free(str);
			ft_error();
		}
		free(str);
	}
}

int	main(int ac, char **av)
{
	t_push	stack;
	char	*arg;
	char	**args;
	int		*nbr;

	if (ac > 1)
	{
		arg = ft_joing_arg(av);
		args = ft_split(arg, ' ');
		free(arg);
		if (!ft_check(args))
		{
			ft_free_args(args);
			ft_error();
		}
		ft_check_int_range(args);
		ft_store(args, &stack, &nbr);
		ft_apply(&stack.a, &stack.b);
		ft_check_if_sort(&stack.a, &stack.b);
		ft_free_stack(&stack.a, &stack.b);
	}
	return (0);
}
