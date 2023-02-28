#include "push_swap.h"

void ft_lst_print(t_list *a)
{
    t_list *node;
    node = a;
    while (node != NULL)
    {
        printf("-----%p-----\n", node);
        node = node->next;
    }
}

int main()
{
    t_push stack;
    // t_list *a;
    // t_list *b;



    // a = malloc(sizeof(t_list));
    // stack.a = NULL;
    // b = malloc(sizeof(t_list));
    
    int arr[] =  {1, 2, 3, 0};
    int i = 0;
    while (arr[i] != 0)
    {
        ft_lstadd_back(&stack.a, ft_lstnew(&arr[i]));
        i++;
    }
    ft_lst_print(stack.a);
}