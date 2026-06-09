NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = ft_printf.h
SRC = ft_printf.c			\
	./utils/ft_putchar.c	\
	./utils/ft_putint.c		\
	./utils/ft_putlong.c	\
	./utils/ft_putptr.c		\
	./utils/ft_putstr.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all