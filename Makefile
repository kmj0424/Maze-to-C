NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRCS = main.c \
		image.c \
		map.c \
		draw.c \
		set.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_itoa.c \
		ft_split.c \
		ft_strjoin.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C ./mlx
		$(CC) $(OBJS) -o $(NAME) -I./ -Lmlx -lmlx -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
		rm -f $(OBJS)
		make clean -C mlx

fclean: clean
		rm -f $(NAME)

re: fclean all

`PHONY: all clean fclean re