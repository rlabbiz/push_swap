CC = CC 
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
MAIN_FILE = push_swap.c
DEPF = push_swap.h
OBJECTS = ft_store.o push_swap_ultis1.o
LIBFT = libft/libft.a

.PHONY : make clean re fclean

%.o : %.c $(DEPF)
	@$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(MAIN_FILE) $(LIBFT) $(OBJECTS) $(DEPF)
	@$(CC) $(CFLAGS) $(MAIN_FILE) $(LIBFT) $(OBJECTS) -o $(NAME)
	@echo "\tPUSH_SWAP Programm Is Created"

$(LIBFT) : 
	@make bonus -C libft

clean : 
	@rm -rf *.o
	@make clean -C libft

fclean : clean
	@rm $(NAME)
	@make fclean -C libft 

re : fclean all