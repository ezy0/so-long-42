# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 18:28:03 by migmoren          #+#    #+#              #
#    Updated: 2023/02/22 19:35:09 by migmoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra

SRC = main.c ft_init.c

OBJS = ${SRC:.c=.o}

.c.o: ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_LIBFT)
	@ar rsc $(NAME) $(OBJS) $(OBJS_LIBFT)

clean:
	@rm -f $(OBJS) $(OBJS_LIBFT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re