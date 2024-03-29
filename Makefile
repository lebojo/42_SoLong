# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 21:58:57 by jchapell          #+#    #+#              #
#    Updated: 2023/06/01 18:51:52 by jchapell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable Name
ENAME	=	so_long
NAME	=	so_long.a
CFLAGS	=	-Wall -Werror -Wextra
AR		=	ar -rsc
FILES	=	main.c parse.c console.c build.c movements.c free.c\
			MENU/start.c key.c matrix.c utils.c physics.c draw.c \
			init.c animation.c parse_validity.c map_validity.c hud.c \
			MENU/level_selector.c draw_cell.c process.c vector.c shortcut.c

# Path for .c , .h and .o Files 
LIBFT	=	./inc/libft/libft.a
MLX 	:= ./inc/minilibx_macos/libmlx.a
SRC_PATH := ./
OBJ_PATH := ./OBJ/
MLX_PATH := ./inc/minilibx_macos

# Compliation under Mac OS
ifeq ($(shell uname),Darwin)
MLX 		:= ./inc/minilibx_macos/libmlx.a
INC_PATH 	:= -I ./inc/libft/ -I ./inc/minilibx_macos/ -I ./inc
LINKER 		:= -L ./inc/minilibx_macos/ -lmlx -lm
FRAMEWORK 	:= -framework Appkit -framework OpenGl

# Compliation under anything else (but only work under linux)
else
INC_PATH := -I ./inc/libft/ -I ./inc/minilibx-linux -I ./inc
LINKER := -L ./inc/minilibx-linux -lmlx -lX11 -lXext -lm
FRAMEWORK :=
MLX_PATH := ./inc/minilibx-linux
endif

all : $(LIBFT) $(MLX) $(NAME)

$(MLX) :
	@echo [INFO] Compliling minilibx
	@make -C $(MLX_PATH)

$(LIBFT) :
	@echo [INFO] Compliling libft
	@make -C ./inc/libft

# Files to compile
OBJ1 := $(FILES:.c=.o)
OBJ := $(patsubst %,$(OBJ_PATH)%,$(OBJ1))

# Build .o first
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo [CC] $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC_PATH)     

# Build final Binary
$(NAME): $(OBJ) $(MLX)
	@echo [INFO] Creating $(Shell uname) Binary Executable [$(NAME)]
	$(AR) $(NAME) $(OBJ) $(LINKFLAGS)
	$(CC) $(CFLAGS) $(NAME) $(LIBFT) $(MLX) $(INC_PATH) $(FRAMEWORK) $(LINKER) -o $(ENAME)

# Clean all the object files and the binary
clean:   
	@echo "[Cleaning]"
	@$(RM) -rfv $(OBJ_PATH)*.o
	@$(RM) -rfv $(OBJ_PATH)/MENU/*.o

fclean: clean
		@$(RM) -rfv $(NAME)
		@$(RM) -rfv $(ENAME)
deepclean : fclean
		@make fclean -C ./inc/libft
		@make clean -C $(MLX_PATH)
re: fclean all

san: all
	$(CC) $(CFLAGS) $(NAME) $(LIBFT) $(MLX) $(INC_PATH) $(FRAMEWORK) $(LINKER) -fsanitize=address -o $(ENAME)

.PHONY : clean fclean re