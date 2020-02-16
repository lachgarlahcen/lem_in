# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 20:31:46 by llachgar          #+#    #+#              #
#    Updated: 2020/02/16 06:31:04 by oaghzaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lemin

SRC_NAME = 	ants_farm.c \
			bfs.c \
			for_debugg.c \
			lengths.c \
			multi_paths.c \
			parsing.c \
			set_links.c \
			set_path.c \
			set_rooms.c \
			sort_rooms.c \
			the_core.c \
			tools.c \
			free.c 

OBJ_NAME =	$(SRC_NAME:.c=.o)

SRC_PATH =	source
OBJ_PATH =	objet

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))



CFLAGS = -Wall -Wextra -Werror

INCLUDE =	-Iinclude \
			-Isource/ft_printf/headers

LIBS =	source/checker/checker.a \
		source/ft_printf/libftprintf.a

DEPS = include/lem_in.h

LIB_C = checker_c \
		printf_c 


all: $(NAME)

$(NAME): $(OBJ) $(LIB_C) 
	@clear;
	@echo "		         Made by : \033[1;91m LLACHGAR\033[m       ";
	@gcc $(OBJ) $(LIBS) -o $@


printf_c:
	@make -C source/ft_printf

checker_c:
	@make -C source/checker

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(DEPS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@clear;
	@echo "Compiling \033[1;36m[$<]\033[0m to \033[1;32m[$@]\033[0m"
	@gcc $(CFLAGS) -g $(INCLUDE) -o $@ -c $<

clean:
	@make clean -C source/ft_printf
	@make clean -C source/checker
	@echo "\033[1;33mRemoving $(NAME)'s objects directory\033[0m"
	@rm -rf $(OBJ_PATH) 2> /dev/null

fclean: clean
	@make fclean -C source/ft_printf
	@make fclean -C source/checker
	@echo "\033[1;33mRemoving $(NAME)\033[0m"
	@/bin/rm -f $(NAME)

re: fclean all
