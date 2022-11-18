# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 17:06:37 by aloez-g           #+#    #+#              #
#    Updated: 2022/11/18 12:54:35 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_INC	=	includes
SRC_DIR		=	./src
SRC			=	$(wildcard $(SRC_DIR)/*.c) \
				$(wildcard $(SRC_DIR)/**/*.c)

OBJ		= 	$(patsubst %.c, %.o, ${SRC})

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
I_FLAG		=	-I $(LIBFT_INC)

%.o : %.c
	@$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@

NAME		= 	libft.a

all:			${NAME}
$(NAME):	$(OBJ)	
			@ar -rc ${NAME} ${OBJ}
			@ar -s ${NAME}
clean:
			@rm -f ${OBJ}
fclean:		clean
			@rm -f ${NAME}
re:			fclean all
.PHONY:		all clean fclean re
