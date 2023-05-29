# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 18:28:03 by migmoren          #+#    #+#              #
#    Updated: 2023/05/29 13:59:38 by migmoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Imlx #Werror

LMX = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = main.c ft_init.c ft_map.c ft_validate.c ft_handler.c ft_mlx.c ft_renderize.c

OBJS = ${SRC:.c=.o}

SRC_LIBFT = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_toupper.c \
			libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_strlen.c libft/ft_strlcpy.c \
			libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_memset.c libft/ft_memcpy.c \
			libft/ft_memmove.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c \
			libft/ft_strjoin.c libft/ft_split.c libft/ft_strtrim.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c \
			libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
			libft/ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c \
			libft/ft_lstclear_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c \
			libft/ft_printf.c libft/ft_print_s.c libft/ft_print_p.c libft/ft_print_nbr.c libft/get_next_line.c

OBJS_LIBFT	= ${SRC_LIBFT:.c=.o}

#.c.o: ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_LIBFT)
	$(CC) $(OBJS) $(OBJS_LIBFT) $(LMX) -o $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_LIBFT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re