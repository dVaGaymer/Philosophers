# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 01:42:35 by alopez-g          #+#    #+#              #
#    Updated: 2023/01/05 20:59:37 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

#----- HEADER -----
H_DIR	=	include
H		=	include/error.h \
			include/log.h \
			include/macro.h \
			include/main.h \
			include/parser.h \
			include/philo.h \
			include/philo_actions.h \
			include/philo_utils.h \
			include/thread.h \
			include/vital_functions.h
H_NODIR	=	$(notdir $(H))

#----- SRC ----
SRC_DIR	=	src
SRC		=	src/actions/philo_actions.c \
			src/error/error.c \
			src/log/log.c \
			src/main.c \
			src/parser/parser.c \
			src/thread/mutex_utils.c \
			src/thread/thread.c \
			src/utils/philo_utils.c \
			src/utils/std_utils.c \
			src/vital_funcs/vital_functions.c

#----- OBJ -----
OBJ_DIR	=	obj
OBJ		=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

#----- LIBS -----

#----- FLAGS -----
CC			=	gcc
H_FLAGS		=	-I$(H_DIR)
C_FLAGS		=	-c -Wall -Wextra -Werror
				-fsanitize=thread
LIB_FLAGS	=	-lpthread
				-fsanitize=thread

#----- RULES
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir $(sort $(dir $(OBJ)))

$(NAME): $(filter-out obj/bonus/%.o, $(OBJ))
	$(CC) $(LIB_FLAGS) $(filter-out obj/bonus/%.o, $(OBJ)) -o $@

bonus: $(filter obj/bonus/%.o, $(OBJ))
	$(CC) $(LIB_FLAGS) $(filter obj/bonus/%.o, $(OBJ)) -o $(NAME)_$@

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) -rf $(OBJ_DIR)
	$(RM) $(NAME)
	$(RM) $(NAME)_bonus

re: fclean all

n:
	norminette

#----- IMPICIT RULES -----
$(addprefix $(OBJ_DIR)/, %.o):	$(addprefix $(SRC_DIR)/, %.c) $(H)
	@$(CC) $(H_FLAGS) $(C_FLAGS) $< -o $@
.PHONY: clean fclean re all

#----- UTILS -----
RED				=	\033[0;31m
CYAN			=	\033[0;36m
GREEN 			=	\033[1;32m
YELLOW 			=	\033[1;33m
NC 				=	\033[0m
