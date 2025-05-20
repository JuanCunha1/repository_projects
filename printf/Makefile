# Compiler and flags
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# Archive and remove
AR			=	ar rcs
RM			=	rm -f

# Project output
LIBFT		= 	libft

NAME		=	libftprintf.a

SRCS		=	ft_printf.c		\
				ft_print.c

OBJS		=	${SRCS:.c=.o}

INCLUDE		= 	ft_printf.h

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJS)

%.o: %.c  Makefile $(INCLUDE)
			$(CC) $(CFLAGS) -c $< -o $@
clean:
			@make clean -C $(LIBFT)
			$(RM) $(OBJS)

fclean: clean
			@$(RM) -f $(LIBFT)/libft.a
			$(RM) $(NAME)

re: fclean all
