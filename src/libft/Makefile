# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 04:15:26 by pamartin          #+#    #+#              #
#    Updated: 2022/11/14 10:17:13 by algaspar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a
HEADER	= 	libft.h

CC 			= 	gcc
FLAG 		= 	-Wall -Wextra -Werror
OPTION 		= 	-I $(HEADER) -c

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
NO_COLOR    = \033[m

####        MENDATORY	PART
SRC 		= 	ft_isalpha.c		ft_isdigit.c 		ft_isalnum.c \
				ft_isprint.c		ft_toupper.c		ft_tolower.c \
				ft_isascii.c		ft_atoi.c			ft_strlen.c \
														ft_long_atoi.c \
				ft_strncmp.c		ft_strchr.c			ft_strrchr.c \
				ft_memcmp.c			ft_memchr.c			ft_memset.c \
				ft_strnstr.c		ft_bzero.c			ft_strdup.c \
				ft_substr.c			ft_strjoin.c		ft_strtrim.c \
				ft_strmapi.c		ft_striteri.c		ft_putchar_fd.c \
				ft_putstr_fd.c		ft_putendl_fd.c 	ft_split.c 	ft_split_charset.c\
				ft_putnbr_fd.c		ft_memcpy.c			ft_calloc.c \
				ft_itoa.c			ft_memmove.c 		ft_strlcpy.c \
				ft_abs.c			ft_strlcat.c		ft_realloc_int.c \
				free_split.c		ft_strcpy.c			ft_strfchr.c	\
				ft_cmp.c

OBJ 		= 	${SRC:.c=.o}

.c.o:
	@printf "%b" "$(COM_COLOR)Compiling libft : $(OBJ_COLOR) $(@F)";
	@printf "%b\n" "		$(OK_COLOR)[✓]$(NO_COLOR)";
	@${CC} ${FLAG} ${OPTION} $< -o ${<:.c=.o}


${NAME}:	${OBJ}
		@ar -rc ${NAME} ${OBJ}

all:		${NAME}

clean:
		@rm  -f ${OBJ}
		
fclean: 	clean
		@rm  -f ${NAME}

re:		fclean all 




.PHONY:	all clean fclean re bonus
