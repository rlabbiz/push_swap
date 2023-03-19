CC = CC 
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
MAIN_FILE = push_swap.c
DEPF = push_swap.h
OBJECTS = ft_store.o push_swap_ultis1.o push_swap_ultis2.o push_swap_ultis3.o ft_sort.o free_stack.o
NAME_BONUS = checker
MAIN_FILE_BONUS = push_swap_bonus.c
DEPF_BONUS = push_swap_bonus.h
OBJECTS_BONUS = push_swap_ultis_bonus.o get_next_line.o push_swap_ultis1_bonus.o ft_store_bonus.o push_swap_ultis2_bonus.o free_stack_bonus.o
LIBFT = libft/libft.a

.PHONY : make clean re fclean

%.o : %.c $(DEPF)
	@$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(MAIN_FILE) $(LIBFT) $(OBJECTS) $(DEPF)
	@$(CC) $(CFLAGS) $(MAIN_FILE) $(LIBFT) $(OBJECTS) -o $(NAME)
	@echo "\tPUSH_SWAP Programm Is Created"

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(MAIN_FILE_BONUS) $(LIBFT) $(OBJECTS_BONUS) $(DEPF_BONUS)
	@$(CC) $(CFLAGS) $(MAIN_FILE_BONUS) $(LIBFT) $(OBJECTS_BONUS) -o $(NAME_BONUS)
	@echo "\tChecker Programm Is Created"

$(LIBFT) : 
	@make bonus -C libft

clean : 
	@rm -rf *.o
	@make clean -C libft

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make fclean -C libft 

re : fclean all