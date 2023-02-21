# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 21:58:57 by jchapell          #+#    #+#              #
#    Updated: 2023/02/21 22:05:56 by jchapell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
LIBFT		= libft/libft.a
MINILIB		= mlx/libmlx.a
PRINTF		= printf/libftprintf.a
CFLAGS 		= -Wall -Wextra -Werror -Imlx
CC			= cc
SRC_PATH	= ./
OPTIONS		= -g3

SRC 		= 	main.c

SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJS = ${SRCS:.c=.o}
OBJ = ${SRC:.c=.o}

all: ${NAME}

$(LIBFT):
			make -C libft

$(MINILIB):
			make -C mlx

$(PRINTF):
			make -C printf

%.o: %.c
			$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
			$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			${RM} ${OBJS}
			make fclean -C libft
			make clean -C mlx
			make fclean -C printf

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: re ignore fclean clean all $(LIBFT) $(NAME) $(MINILIB) $(PRINTF)