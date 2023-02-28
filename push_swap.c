/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:37:57 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/02/28 12:56:25 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(t_list *head)
{
	t_list *lst;

	lst = head;
	printf("Value\tAddres\n");
	printf("-----\t------\n");
	while (lst != NULL)
	{
		printf("%d\t%p\n", *(int *)lst->content, lst);
		lst = lst->next;
	}
}

char *ft_joing_arg(char **av)
{
	char *str;

	str = ft_strdup(" ");
	av++;
	while (*av)
	{
		str = ft_strjoin(str, *av);
		str = ft_strjoin(str, " ");
		av++;
	}
	return (str);
}

void	ft_store(char **str, t_push *stack)
{
	int *nbr;
	int len = 0;
	int j = 0;
	
	while (str[len] != NULL)
		len++;
	
	nbr = (int *)malloc(sizeof(int ) * len);
	int i = 0;
	while (str[i] != NULL)
	{
		nbr[i] = ft_atoi(str[i]);
		i++;
	}
	i = len - 1;
	while (i >= 0)
	{
		j = i + 1;
		while (j < len)
		{
			if (nbr[i] == nbr[j])
				ft_error();
			j++;
		}
		i--
		;
	}
	i = 0;
	while (i < len)
	{
		ft_lstadd_back(&stack->a, ft_lstnew(&nbr[i]));
		i++;
	}
	free(nbr);
}

void ft_swap(t_list **head, int c)
{
	if (c == 'a' || c == 'b')
	{
		t_list *a = *head;
		if (!a || a->next == NULL)
			return ;	
		void *nbr = a->content;
		// t_list *tmp = a;
		a->content = a->next->content;
		a->next->content = nbr;
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	if (ac > 1 && ft_check(ft_split(ft_joing_arg(av), ' ')))
	{
		t_push stack;

		ft_store(ft_split(ft_joing_arg(av), ' '), &stack);

		// ft_print_lst(stack.a);
		printf("**%d**\t%p\n", *(int *)stack.a->next->content, stack.a->next);
		// ft_push_b(&stack);
		ft_push_b(&stack.a);
		printf("**%d**\t%p\n", *(int *)stack.a->content, stack.a);
		
		// ft_swap(&stack.a, 'a');
		
		printf("############################\n");
		
		ft_print_lst(stack.a);
	}
	else
		ft_error();
	return (0);
}