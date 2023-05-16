# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 21:58:57 by jchapell          #+#    #+#              #
#    Updated: 2023/05/16 05:45:45 by lebojo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
LIBFT		= libft/libft.a
MINILIB		= mlx/libmlx.a
CFLAGS 		= -Wall -Wextra -Werror -Imlx
CC			= cc
SRC_PATH	= ./

SRC 		= 	main.c parse.c console.c build.c movements.c \
				MENU/start.c key.c matrix.c utils.c physics.c draw.c \
				init.c animation.c parse_validity.c map_validity.c hud.c

SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJS = ${SRCS:.c=.o}
OBJ = ${SRC:.c=.o}

all: ${NAME}

$(LIBFT):
			make -C libft

$(MINILIB):
			make -C mlx

%.o: %.c
			$(CC) -g -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
			$(CC) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			${RM} ${OBJS}
			make fclean -C libft
			make clean -C mlx
			make fclean -C printf

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: re ignore fclean clean all $(LIBFT) $(NAME) $(MINILIB) $(PRINTF)
