# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 18:28:03 by migmoren          #+#    #+#              #
#    Updated: 2023/07/06 18:12:18 by migmoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc -Wall -Wextra -Werror -g -fsanitize=address

INCLUDE = -Llibft -lft -I ./ -I mlx

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = main.c ft_init.c ft_map.c ft_validate.c ft_handler.c ft_mlx.c ft_renderize.c
OBJS = ${SRC:.c=.o}

%.o: %.c libft/libft.a
	${CC} $< -c -o $@

all: libft ${NAME}

libft:
	@make bonus -C libft

${NAME}: ${OBJS} 
	${CC} ${SRC} ${INCLUDE} ${MLX} -o ${NAME}

clean:
	@make clean -C libft
	@rm -f ${OBJS}

fclean: clean
	@make fclean -C libft
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re libft