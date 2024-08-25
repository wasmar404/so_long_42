CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L./mlx -lmlx -L./mlx -lXext -lX11 -lm
SRC =   libft/ft_split.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		get_next_line.c \
		main.c \
		maponscreen.c \
		on_key_press.c \
		error_check_helper.c \
		error_check.c\
		map_to_2d_array.c \
		check.c \
		run_destroy.c \
        printf/ft_lowercase_x.c \
        printf/ft_unsigned_decimal.c \
        printf/ft_putchar.c \
        printf/ft_percent.c \
        printf/ft_putnbr.c \
        printf/ft_pointer.c \
        printf/ft_putstr.c \
        printf/ft_printf.c\
		check_valid_path.c\
		free.c\
		check_valid_path_helper.c\
		get_map_info.c\
		check_1.c\
		on_key_press_helper.c\

        
OBJ = $(SRC:.c=.o)
EXEC = so_long

all: $(EXEC)

$(EXEC): $(OBJ)
		$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(EXEC) $(LIB)

re: fclean all
.PHONY: all bonus clean fclean re