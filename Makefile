## **************************************************************************** #
##                                                                              #
##                                                         :::      ::::::::    #
##    Makefile                                           :+:      :+:    :+:    #
##                                                     +:+ +:+         +:+      #
##    By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+         #
##                                                 +#+#+#+#+#+   +#+            #
##    Created: 2023/03/12 02:35:33 by psuanpro          #+#    #+#              #
##    Updated: 2023/03/12 18:38:01 by psuanpro         ###   ########.fr        #
##                                                                              #
## **************************************************************************** #

NAME		= cub3D

MAIN		= main.c
MAIN_DIR	= ./

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -Imlx
#CFLAGS		= -g -Wall -Werror -Wextra

SRC_DIR		= ./srcs/

MODULE1		=	main.c add_list.c check_data.c check_map.c error.c fah_split.c \
				get_data.c get_data2.c get_map.c init.c parser1.c utils.c \
				util2.c get_map2.c

# MODULE2		= process.c \
# 				minimap.c \
# 				minimap_utils.c \
# 				key_hook.c \
# 				key_hook_utils.c \
# 				lodev.c \
# 				lodev_utils.c \
# 				draw_scene.c \
# 				background.c \
# 				hand_animation.c \
# 				key_hook_keys.c

# MODULE3		= free.c

# MODULE4		= init.c \
# 				init_utils.c

# MODULE5		= print_msg_utils.c \
# 				print_str.c \
# 				file_utils.c \
# 				str_utils.c \
# 				int_utils.c


MODULE1_DIR	= ./srcs/
# MODULE2_DIR = ./src/process/
# MODULE3_DIR = ./src/free/
# MODULE4_DIR = ./src/init/
# MODULE5_DIR = ./src/utils/

LIB_DIR		= ./libft/
MLX = mlx/libmlx.a
INCLUDE_MLX = -framework OpenGL -framework AppKit
LIBFT = libft.a
LIB =	${addprefix $(LIB_DIR),$(LIBFT)} \
#		${addprefix $(LIB_DIR),$(MLX)}


OBJ_DIR		= ./obj/

OBJS		= ${addprefix $(OBJ_DIR),$(MODULE1:.c=.o)}
#   ${addprefix $(OBJ_DIR),$(MODULE2:.c=.o)} \
			#   ${addprefix $(OBJ_DIR),$(MODULE3:.c=.o)} \
			#   ${addprefix $(OBJ_DIR),$(MODULE4:.c=.o)} \
			#   ${addprefix $(OBJ_DIR),$(MODULE5:.c=.o)} \
			#   ${addprefix $(OBJ_DIR),$(MAIN:.c=.o)}

RM = rm -rf


BRED =\033[1;31m
BGRN =\033[1;32m
BYEL =\033[1;33m
RES = \033[0m
BLU = \033[0;34m

COMPILE = echo "$(BGRN)$(NAME) compiled....$(RES)"
CLEAN = echo "$(BYEL)$(NAME) clean....$(RES)"
FCLEAN = echo "$(BRED)$(NAME) fclean....$(RES)"

LOAD = bash ./src/script/animation.sh $(MODULE1) $(MODULE2) $(MODULE3) $(MODULE4) $(MODULE5);
CUBE =  echo '$(BLU)________$(RES)/\\\\\\\\\\\\\\\\\\$(BLU)________________$(RES)/\\\\\\$(BLU)____________$(RES)/\\\\\\\\\\\\\\\\\\\\$(BLU)___$(RES)/\\\\\\\\\\\\\\\\\\\\\\\\$(BLU)____$(RES)         '; \
		echo ' $(BLU)_____$(RES)/\\\\\\////////$(BLU)________________$(RES)\\/\\\\\\$(BLU)__________$(RES)/\\\\\\///////\\\\\\$(BLU)_$(RES)\\/\\\\\\////////\\\\\\$(BLU)__$(RES)        '; \
		echo '  $(BLU)___$(RES)/\\\\\\/$(BLU)_________________________$(RES)\\/\\\\\\$(BLU)_________$(RES)\\///$(BLU)______$(RES)/\\\\\\$(BLU)__$(RES)\\/\\\\\\$(BLU)______$(RES)\\//\\\\\\$(BLU)_$(RES)       '; \
		echo '   $(BLU)__$(RES)/\\\\\\$(BLU)______________$(RES)/\\\\\\$(BLU)____$(RES)/\\\\\\$(BLU)_$(RES)\\/\\\\\\$(BLU)________________$(RES)/\\\\\\//$(BLU)___$(RES)\\/\\\\\\$(BLU)_______$(RES)\\/\\\\\\$(BLU)_$(RES)      '; \
		echo '    $(BLU)_$(RES)\\/\\\\\\$(BLU)_____________$(RES)\\/\\\\\\$(BLU)___$(RES)\\/\\\\\\$(BLU)_$(RES)\\/\\\\\\\\\\\\\\\\\\$(BLU)_________$(RES)\\////\\\\\\$(BLU)__$(RES)\\/\\\\\\$(BLU)_______$(RES)\\/\\\\\\$(BLU)_$(RES)     '; \
		echo '     $(BLU)_$(RES)\\//\\\\\\$(BLU)____________$(RES)\\/\\\\\\$(BLU)___$(RES)\\/\\\\\\$(BLU)_$(RES)\\/\\\\\\////\\\\\\$(BLU)___________$(RES)\\//\\\\\\$(BLU)_$(RES)\\/\\\\\\$(BLU)_______$(RES)\\/\\\\\\$(BLU)_$(RES)    '; \
		echo '      $(BLU)__$(RES)\\///\\\\\\$(BLU)__________$(RES)\\/\\\\\\$(BLU)___$(RES)\\/\\\\\\$(BLU)_$(RES)\\/\\\\\\$(BLU)__$(RES)\\/\\\\\\$(BLU)__$(RES)/\\\\\\$(BLU)______$(RES)/\\\\\\$(BLU)__$(RES)\\/\\\\\\$(BLU)_______$(RES)/\\\\\\$(BLU)__$(RES)   '; \
		echo '       $(BLU)____$(RES)\\////\\\\\\\\\\\\\\\\\\_$(RES)\\//\\\\\\\\\\\\\\\\\\$(BLU)__$(RES)\\/\\\\\\\\\\\\\\\\\\$(BLU)__$(RES)\\///\\\\\\\\\\\\\\\\\\/$(BLU)___$(RES)\\/\\\\\\\\\\\\\\\\\\\\\\\\/$(BLU)___$(RES)  '; \
		echo '        $(BLU)_______$(RES)\\/////////$(BLU)___$(RES)\\/////////$(BLU)___$(RES)\\/////////$(BLU)_____$(RES)\\/////////$(BLU)_____$(RES)\\////////////$(BLU)_____$(RES) ';

#input
${OBJ_DIR}%.o: ${MODULE1_DIR}%.c
	$(CC) -g $(CFLAGS) -c -o $@ $^

#process
# ${OBJ_DIR}%.o: ${MODULE2_DIR}%.c
# 	$(CC) -g $(CFLAGS) -c -o $@ $^

# #free
# ${OBJ_DIR}%.o: ${MODULE3_DIR}%.c
# 	$(CC) -g $(CFLAGS) -c -o $@ $^

# #init
# ${OBJ_DIR}%.o: ${MODULE4_DIR}%.c
# 	$(CC) -g $(CFLAGS) -c -o $@ $^

# ${OBJ_DIR}%.o: ${MODULE5_DIR}%.c
# 	$(CC) -g $(CFLAGS) -c -o $@ $^

all: ${OBJ_DIR} ${NAME}
# @$(LOAD)
#	@sleep 0.5
# @$(CUBE)



${OBJ_DIR}:
	@mkdir -p $(OBJ_DIR)

# ${OBJ_DIR}%.o: ${MAIN_DIR}%.c
# 	$(CC) -c -o $@ $^

${NAME}: ${OBJS}
	@make -C ./libft
#@make -C ./libft/mlx
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(CFLAGS)
# $(CC) $(OBJS) $(INCLUDE_MLX) -o $(NAME) $(LIB) $(CFLAGS)
#$(CC) $(OBJS) -o $(NAME) $(LIB) $(CFLAGS)

run: re
	./cub3d map/minimalist.cub

runn: re
	./cub3d map/minimaldoor.cub

clean:
	@make -C ./libft clean
# @make -C ./include/mlx clean
#	@echo "$(BYEL)Mlx Clean....$(RES)"
	@$(RM) $(OBJ_DIR)
	@$(RM) *.dSYM
	@$(CLEAN)

fclean: clean
	@make -C ./libft fclean
	@$(RM) $(NAME)
	@$(FCLEAN)

re: fclean all
