NAME = push_swap

SRCDIR = .
LIBFTDIR = Libft
PRINTFDIR = ft_printf

LIBFT = $(LIBFTDIR)/libft.a
PRINTF = $(PRINTFDIR)/libftprintf.a

SRC = $(wildcard $(SRCDIR)/*.c)

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(PRINTF):
	$(MAKE) -C $(PRINTFDIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(PRINTFDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(PRINTFDIR) fclean

re: fclean all

.PHONY: all clean fclean re