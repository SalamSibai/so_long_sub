NAME	= libftprintf.a
FILES	= ft_printf.c pf_hex_utilities.c pf_utilities.c

OBJS	= $(FILES:.c=.o)
CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re