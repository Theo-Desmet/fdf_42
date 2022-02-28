NAME = fdf

SRC =	./src/main.c\
	./src/read_map.c\

LIB_PATH = libft/

CC = @clang

CFLAGS = -g #-Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

%.o:%.c fdf.h
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: subsystem $(NAME)

subsystem:
	@cd $(LIB_PATH) && make all

$(NAME): begin $(OBJ)
	@make -C $(LIB_PATH) all
	@make -C mlx_linux/ all
	$(CC) $(OBJ)  libft/libft.a mlx_linux/libmlx.a -lXext -lX11 -o $(NAME)
	@echo "\033[106;32mcompilation de fdf terminées\033[0m"	

#@$(CC) $(OBJ) $(LIB_PATH)libft.a -o $(NAME)

clean:
	@make -C $(LIB_PATH) fclean
	@rm -f $(OBJ)
	@echo "\033[101;30msuppression des fichier *.o de fdf\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[101;30msuppression de l'executable fdf\033[0m"

re: fclean all

begin:
	@echo "\033[106;35mdebut de la compilation de fdf\033[0m"

.PHONY: all clean fclean re

