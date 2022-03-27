CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra

RM			= rm -f

NAME		= pipex

SRCS		= pipex.c ft_open_file.c ft.c

LIBFT_PATH	= libft/

OBJS		= ${SRCS:.c=.o}

all:		$(NAME)

${NAME}:	${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all