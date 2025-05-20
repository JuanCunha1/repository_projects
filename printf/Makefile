# Compiler and flags
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -c

# Archive and remove
AR			=	ar rcs
RM			=	rm -f

# Project output
LIBFT		= 	libft

NAME		=	libprintf.a

SRCS		=	libprintf.c		\
				ft_print.c

OBJS		=	${SRCS:.c=.o}

INCLUDE		= 	libprintf.h

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)

%.o: %.c  Makefile $(INCLUDE)
			$(CC) $(CFLAGS) $< -o $@
clean:
			@make clean -C $(LIBFT)
			$(RM) $(OBJS)

fclean: clean
			@$(RM) -f $(LIBFT)/libft.a
			$(RM) $(NAME)

re: fclean all
