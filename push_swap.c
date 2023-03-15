/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:37:57 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/03/15 08:29:48 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

void	ft_print_lst(t_list *head)
{
	t_list *lst;

	lst = head;
	printf("Value\tAddres\n");
	printf("-----\t------\n");
	while (lst != NULL)
	{
		printf("%d\t%p\n", lst->content, lst);
		lst = lst->next;
	}
}

void	ft_check_empty(char *str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		ft_error();
}

char *ft_joing_arg(char **av)
{
	char *str;

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
	int i = 0;
	int check = 0;
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

int	ft_store(char **str, t_push *stack, int **nbr)
{
	int len = 0;
	int j = 0;
	int i = 0;
	// int check = 1;

	while (str[len] != NULL)
		len++;

	(*nbr) = (int *)malloc(sizeof(int ) * len);
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

	i = len - 1;
	while (i >= 0)
	{
		ft_lstadd_front(&stack->a, ft_lstnew((*nbr)[i]));
		i--;
	}
	return (len);
}

void ft_swap(t_list **head, char *str)
{
	t_list *a = *head;
	if (!a || a->next == NULL)
		return ;	
	int nbr = a->content;
	a->content = a->next->content;
	a->next->content = nbr;
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

void ft_swap_all(t_list **a, t_list **b, char *str)
{
	ft_swap(a, NULL);
	ft_swap(b, NULL);
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	ft_check_content(int a, int b)
{
	if (a <= b)
		return (1);
	return (0);
}

int	ft_get_index(t_list *stack, int value)
{
	t_list *lst = stack;
	int index = 0;

	while (lst != NULL && lst->content != value)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

void	ft_sort(t_list **a, t_list **b, int *nbr, int len)
{
	int start;
	int end = 0;

	int i = 0;
	start = 0;
	end = 18;
	while ((*a) != NULL)
	{
		i = 0;
		while (i < len)
		{
			if ((*a)->content == nbr[i])
			{
				if (i >= start && i <= end)
				{
					ft_push_b(a, b, "pb");
					if (end < len)
					{
					start++;
					end++;
					}
				}
				else if (i < start)
				{
					ft_push_b(a, b, "pb");
					ft_rotate(b, "rb");
					if (end < len)
					{
					start++;
					end++;
					}
				}
				else if (i > end)
					ft_rotate(a, "ra");
				break ;
			}
			i++;
		}
	}
}

void	ft_sort_array(int *nbr, int len)
{
	int i = 0;
	int tmp;
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

void	ft_final_sort(t_list **a, t_list **b, int len, int *nbr)
{
	int i = 1;
	int index = 0;
	while ((*b) != NULL)
	{
		index = ft_get_index(*b, nbr[len - i]);
		if (index > 0 && index <= (len-i) / 2)
		{
			while ((*b)->content != nbr[len - i])
			{
				ft_rotate(b, "rb");
			}
		}
		else if (index > 0 && index > (len-i) / 2)
		{
			index = (len - 1) - index;
			while ((*b)->content != nbr[len - i])
			{
				ft_rrotate(b, "rrb");
			}
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

int	ft_check_int_range(char **str)
{
	int i = 0;
	int j = 0;
	long long	nbr;
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

void ft_free_args(char **str)
{
	int i = 0;
	while (str[i] != NULL)
	{
		
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		char *arg = ft_joing_arg(av);
		char **args = ft_split(arg, ' ');
		int *nbr = NULL;

		free(arg);
		if (!ft_check(args))
		{
			while (*args != NULL)
			{
				free(*args);
				args++;
			}
			ft_error();
		}
		t_push stack;
		
		// check int range
		ft_check_int_range(args);

		// store the list of numbers in stack A
		int len = ft_store(args, &stack, &nbr);

		// ft_print_lst(stack.a);

		// sort array
		ft_sort_array(nbr, len);
		
		ft_sort(&stack.a, &stack.b, nbr, len);

		// print stack B
		// ft_print_lst(stack.b);

		ft_final_sort(&stack.a, &stack.b, len, nbr);

		// print stack B
		// ft_print_lst(stack.a);

		// print stack B
		// ft_print_lst(stack.b);

		// pause();
	}
	return (0);
}
