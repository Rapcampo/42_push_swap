NAME	= push_swap
CC	= gcc
FLAGS	= -Wall -Werror -Wextra
LIBFT	= libft/libft.a
LIBFT_DIR	= libft/
SOURCE	= *.c
OBJS	= $(SOURCE:.c=.o)
RM = rm -rf

# ansi escape codes

UNDERLINE = \e[4m
BLINK = \e[5m
GREEN = \e[92m
RESET = \e[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "\n*************************$(GREEN)$(BLINK)    [Compilation Sucessfull!]    $(RESET)*************************\n"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS): $(SOURCE)
	$(CC) $(FLAGS) -c $(SOURCE)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\n*************************$(BLINK)$(GREEN)    [Success!]    $(RESET)*************************\n"
	@echo "$(UNDERLINE)Objects have been removed sucessfully$(RESET)"

fclean:
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	@echo "\n*************************$(BLINK)$(GREEN)    [Success!]    $(RESET)*************************\n"
	@echo "$(UNDERLINE)Static library and programs removed successfully$(RESET)"

re: fclean all

.SILENT: all clean fclean re

.PHONY: all clean fclean re
