# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 18:24:32 by faventur          #+#    #+#              #
#    Updated: 2022/07/20 11:58:41 by faventur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c ft_split.c ft_strjoin.c ft_puterror.c ft_path_searcher.c \
	libftools.c pipex.c hd_managing.c get_next_line.c ft_fprintf.c \
	ft_fprintf_basic.c ft_fprintf_utils.c

OBJS = $(addprefix srcs/, ${SRCS:.c=.o})

FLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

RM = rm -f

NAME = pipex

NONE = \033[0m
HIGREEN = \033[92m
HIBLUE = \033[94m
CURSIVE = \033[3m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(HIGREEN)No! Try not! Do! Or do not! There is no try.$(NONE)"
	@echo "$(CURSIVE)Master Yoda$(NONE)"
	@gcc $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(HIBLUE)Philosopher, c'est apprendre à mourir.$(NONE)"
	@echo "Montaigne, $(CURSIVE)Les Essais$(NONE)"
	@rm $(OBJS)

.c.o:
	gcc $(FLAGS) -c -I./includes $< -o ${<:.c=.o}

exe: all
	@./$(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
