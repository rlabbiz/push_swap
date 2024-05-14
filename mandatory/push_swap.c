/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:37:57 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/19 12:06:38 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **a)
{
	if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
		ft_rotate(a, "ra");
	if ((*a)->content > (*a)->next->content)
		ft_swap(a, "sa");
	if ((*a)->next->content > (*a)->next->next->content)
	{
		ft_swap(a, "sa");
		ft_rotate(a, "ra");
	}
	if ((*a)->content > (*a)->next->content)
		ft_swap(a, "sa");
}

void	ft_sort_4(t_list **a, t_list **b, int *nbr)
{
	if ((*a)->content == nbr[0] || (*a)->next->content == nbr[0])
	{
		while ((*a)->content != nbr[0])
			ft_rotate(a, "ra");
	}
	else
	{
		while ((*a)->content != nbr[0])
			ft_rrotate(a, "rra");
	}
	ft_push_b(a, b, "pb");
	ft_sort_3(a);
	ft_push_a(a, b, "pa");
}

void	ft_sort_less_than(t_list **a, t_list **b, int len, int *nbr)
{
	if (len == 2)
		ft_swap(a, "sa");
	else if (len == 3)
		ft_sort_3(a);
	else if (len == 4)
		ft_sort_4(a, b, nbr);
	else if (len == 5)
	{
		if ((*a)->content == nbr[0] || (*a)->next->content == nbr[0])
		{
			while ((*a)->content != nbr[0])
				ft_rotate(a, "ra");
		}
		else
		{
			while ((*a)->content != nbr[0])
				ft_rrotate(a, "rra");
		}
		ft_sort_4(a, b, nbr);
		ft_push_b(a, b, "pb");
		ft_push_a(a, b, "pa");
		ft_push_a(a, b, "pa");
	}
	exit(0);
}

void	ft_main(char *arg, char **args)
{
	free(arg);
	if (!ft_check(args))
	{
		ft_free_args(args);
		ft_error();
	}
	ft_check_int_range(args);
}

int	main(int ac, char **av)
{
	t_push	stack;
	char	*arg;
	char	**args;
	int		*nbr;
	int		len;

	if (ac > 1)
	{
		arg = ft_joing_arg(av);
		args = ft_split(arg, ' ');
		ft_main(arg, args);
		len = ft_store(args, &stack, &nbr);
		ft_free_args(args);
		ft_sort_array(nbr, len);
		if (len >= 6)
		{
			ft_sort(&stack.a, &stack.b, nbr, len);
			ft_final_sort(&stack.a, &stack.b, len, nbr);
		}
		else if (len < 6)
			ft_sort_less_than(&stack.a, &stack.b, len, nbr);
		free(nbr);
		ft_free_stack(&stack.a, &stack.b);
	}
	return (0);
}
