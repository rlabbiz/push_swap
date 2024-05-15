CC = cc 
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
MAIN_FILE = mandatory/push_swap.c
DEPF = includes/push_swap.h
OBJECTS = mandatory/ft_store.o mandatory/push_swap_ultis1.o mandatory/push_swap_ultis2.o mandatory/push_swap_ultis3.o mandatory/ft_sort.o mandatory/free_stack.o
NAME_BONUS = checker
MAIN_FILE_BONUS = bonus/push_swap_bonus.c
DEPF_BONUS = include/push_swap_bonus.h
OBJECTS_BONUS = bonus/push_swap_ultis_bonus.o bonus/get_next_line.o bonus/push_swap_ultis1_bonus.o bonus/ft_store_bonus.o bonus/push_swap_ultis2_bonus.o bonus/free_stack_bonus.o
LIBFT = libft/libft.a

# color difinition
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
MAGENTA = "\033[0;35m"
CYAN = "\033[0;36m"
RESET = "\033[0m"

.PHONY : make clean re fclean

%.o : %.c $(DEPF)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo $(YELLOW)"[+] Compating... $<"$(RESET)

all : $(NAME)

$(NAME) : $(MAIN_FILE) $(LIBFT) $(OBJECTS) $(DEPF)
	@$(CC) $(CFLAGS) $(MAIN_FILE) $(LIBFT) $(OBJECTS) -o $(NAME)
	@echo $(GREEN)"[+] Push_Swap Programm Is Created"$(RESET)
bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(MAIN_FILE_BONUS) $(LIBFT) $(OBJECTS_BONUS) $(DEPF_BONUS)
	@$(CC) $(CFLAGS) $(MAIN_FILE_BONUS) $(LIBFT) $(OBJECTS_BONUS) -o $(NAME_BONUS)
	@echo $(GREEN)"[+] Checker Programm Is Created"$(RESET)

$(LIBFT) : 
	@make bonus -C libft

clean : 
	@rm -rf $(OBJECTS_BONUS) $(OBJECTS)
	@make clean -C libft
	@echo $(RED)"[-] Objects Are Removed"$(RESET)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make fclean -C libft 
	@echo $(RED)"[-] Push_Swap, Checker Programms Are Removed"$(RESET)

re : fclean all