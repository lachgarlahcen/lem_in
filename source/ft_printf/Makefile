# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/19 15:48:17 by oaghzaf           #+#    #+#              #
#    Updated: 2019/12/12 05:31:06 by oaghzaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_FILE = add.c add2.c addition.c algonor.c binaire.c\
check.c float_calc.c freelk.c ft_itoa_long.c inf_case.c\
itoa.c mltp.c multiplication.c power.c print_a.c\
print_b.c print_c.c print_d.c print_e.c print_f.c\
print_lim.c print_o.c print_p.c print_s.c print_u.c\
print_x.c retry.c t64.c t80.c to_binary.c to_hexa.c\
utils_1.c utils_2.c

SRC_DIR = srcs
OBJ_DIR = objs

SRC_LIB =  libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelone.c libft/ft_lstfind.c libft/ft_lstiter.c libft/ft_lstlen.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_lstprint.c libft/ft_lstprintall.c libft/ft_memalloc.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putendl_fd.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strncat.c libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strsplit.c libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c libft/ft_tolower.c libft/ft_toupper.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILE:.c=.o))

OBJ_LIB = $(SRC_LIB:.c=.o)

all :  $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@ar rc $(NAME) $(OBJ_LIB) $(OBJ)
	@echo Done.

$(OBJ) : $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@gcc -Wall -Wextra -Werror -I./headers -c $< -o $@
	@echo $@ created.

$(OBJ_DIR) : 
	@mkdir $(OBJ_DIR)
	@echo create $(OBJ_DIR)

clean :
	@make clean -C libft/ 
	@/bin/rm -rf $(OBJ)
	@echo Deleted.

fclean :	clean
	@make fclean -C libft/ 
	@/bin/rm -rf $(NAME)

re : fclean all
