SRCS = ft_printf.c ft_putchar_pf.c ft_putstr_pf.c ft_putnbr_pf.c ft_unsigned_putnbr_pf.c ft_putnbr_hex_lower_pf.c ft_putnbr_hex_upper_pf.c ft_pointer_pf.c

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f
AR = ar rcs 
CFLAGS = -Wall -Wextra -Werror 

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
