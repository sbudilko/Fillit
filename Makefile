NAME	:= fillit

CFLAGS	:= -Wall -Wextra -Werror

SOURCE	:= create_map.c edit_tetro.c ft_clear_map.c main.c make_tetro_lst.c solve.c validation_file.c print_map.c

all: $(NAME)

$(NAME): $(SOURCE)
	@make all -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SOURCE) ./libft/libft.a -I ./bin/ -I ./libft/
	@echo "\033[0;94m./fillit compiled.\033[0m "

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all
