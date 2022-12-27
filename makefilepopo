# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 11:27:53 by pamartin          #+#    #+#              #
#    Updated: 2022/12/14 11:27:55 by pamartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=		cub3D

###DIRECTORY
SRC			=		./src/
GNL 		= 		$(SRC)gnl/
PARS 		=		$(SRC)parsing/
###FILES
SRC_MANDA	=		$(GNL)gnl.c 				$(GNL)gnl_utils.c \
					$(PARS)parsing.c 			$(PARS)pars_line.c			$(PARS)pars_init.c 	\
					$(PARS)pars_set_color.c		$(PARS)pars_set_texture.c 	$(PARS)pars_map.c	\
					$(PARS)pars_utils.c 		$(PARS)pars_map_utils.c \
					$(SRC)main.c  				$(SRC)utils.c 
					
OBJ			= 		$(SRC_MANDA:.c=.o)

LIB 		= 		$(SRC)libft/libft.a



### COMMANDS
CC			=		gcc
FLAGS		=		-g -fsanitize=address -Wall -Wextra -Werror -static-libsan
#FLAGS		=		-g  -Wall -Wextra -Werror 
RM			=		rm -rf
MAKE 		= 		make
MAKE_CLEAN	= 		make clean
MAKE_FCLEAN = 		make fclean


### NAME
$(NAME)		:		$(OBJ)
	@$(MAKE) -C $(SRC)libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)


### RULES
all			:		$(NAME)

clean		:
	$(RM) $(OBJ)
	$(MAKE_CLEAN) -C $(SRC)libft
fclean		:		clean
	$(RM) $(NAME)
	$(MAKE_FCLEAN) -C $(SRC)libft

re			:		fclean all

.PHONY 		: all clean fclean re
